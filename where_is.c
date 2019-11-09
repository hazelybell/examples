#define _POSIX_C_SOURCE 200809L 
// necessary to use getline()
// we have to define _POSIX_C_SOURCE before any includes!
// this tells the system libraries that we want more modern library functions (up to August 2008)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // for pid_t
#include <unistd.h> // for getpid
#include <stdint.h> // for intptr_t
#include <string.h>
#include <sys/resource.h> // for getrlimit

void *sbrk(intptr_t increment); // for sbrk

// From GNU Linux Programmers Manual, 2017, "man 3 end"
extern char etext, edata, end;

// stuff for this program

// macro for debugging prints
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#define N 5
#define MY_PATH_MAX 101

const char * const ANON = "anonymous memory (more heap)";
const char * const SAM = "statically allocated memory";

struct map {
    void * begin;
    void * end;
    const char * description;
    int ro;
};

struct maps {
    int initialized;
    size_t n;
    struct map * a;
};

struct maps maps = {
    0,
    0,
    NULL
};

const struct map unknown = {
    0,
    0,
    "unknown",
    0
};

void * stack_start = NULL;
void * stack_end = NULL;

char * new_string_copy(const char *s) {
    char * new;
    new = malloc(strlen(s) + 1);
    strcpy(new, s);
    return new;
}

void add_map(struct maps *m) {
    m->n += 1;
    m->a = realloc(
        m->a,
        sizeof(struct map) * m->n);
}

FILE * checked_open_ro(const char * path) {
    FILE * fp;
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Couldn't open file:");
        fprintf(stderr,
                "Error opening %s\n",
                path);
        exit(1);
    }
    return fp;
}

void free_maps() {
    for (size_t i = 0; i < maps.n; i++) {
        free((void *)
            maps.a[i].description);
    }
    free(maps.a);
    maps.initialized = 0;
    maps.n = 0;
    maps.a = NULL;
    stack_start = NULL;
    stack_end = NULL;
    
}

void read_maps(int force_reread) {
    // check if we already read the maps
    if (maps.initialized) {
        if (force_reread) {
            free_maps();
        } else {
            return;
        }
    }
    
    // generate the path to this process's maps file
    char path[MY_PATH_MAX];
    snprintf(
        path,
        MY_PATH_MAX,
        "/proc/%lld/maps",
        (long long) getpid()
    );
    
    // open the file
    FILE *mapsfile = checked_open_ro(path);
    
    char * line = NULL;
    size_t line_len = 0;
    while (getline(&line, &line_len, mapsfile) > 0) {
        void * start;
        void * map_end;
        char * name;
        char flags[5];
        debug(line);
        const int expected = 4;
        int r = sscanf(
            line,
            "%p-%p%4s%*s%*s%*s%ms",
            &start,
            &map_end,
            flags,
            &name
        );
        if (r == expected - 1) {
            name = new_string_copy(ANON);
        } else if (r != expected) abort();
        add_map(&maps);
        struct map * new = &(maps.a[maps.n - 1]);
        void * endp = &end;
        if (
            endp > start
            && endp <= map_end
        ) {
            debug("This one must be the BSS map: %p < %p <= %p\n", start, endp, map_end);
            free(name);
            name = new_string_copy(SAM);
        }
        new->begin = start;
        new->end = map_end;
        new->description = name;
        switch (flags[1]) {
            case 'w':
                new->ro = 0;
                break;
            case '-':
                new->ro = 1;
                break;
            default:
                abort();
        }
        if (strcmp(name, "[stack]") == 0) {
            stack_start = start;
            stack_end = map_end;
        }
    }
    line_len = 0;
    line = realloc(line, 0);
    maps.initialized = 1;
    if (stack_start == NULL) abort();
    if (fclose(mapsfile) != 0) abort();
    
}

const struct map * where_is(const void * ptr) {
    read_maps(0);
    for (size_t i = 0; i < maps.n; i++) {
        struct map * map = &maps.a[i];
        if (
            ptr >= map->begin
            && ptr < map->end
        ) {
            return map;
        }
    }
    read_maps(1);
    for (size_t i = 0; i < maps.n; i++) {
        struct map * map = &maps.a[i];
        if (
            ptr >= map->begin
            && ptr < map->end
        ) {
            return map;
        }
    }
    return &unknown;
}

void describe_pointer(
    const char * name,
    const void * p,
    size_t size
) {
    const struct map * m = where_is(p);
    const char * writable = (
        m->ro ? "read-only" : "writable"
        );
    printf("%s @ %p is %zu %s bytes in %s\n", name, p, size, writable, m->description);
}

// macro trickery!
#define DESCRIBE(p) describe_pointer(#p, &(p), sizeof(p))

void layout() {
#ifdef DEBUG
    describe_pointer(
        "Last byte of program code and constants",
        (&etext)-1,
        1
    );
    describe_pointer(
        "Last byte of program data segment",
        (&edata)-1,
        1
    );
    describe_pointer(
        "Last byte of BSS segment",
        (&end)-1,
        1
    );
    describe_pointer(
        "Last byte of heap data segment", sbrk(0)-1,
        1
    );
    char c = 0;
    describe_pointer(
        "Last byte of stack",
        &c,
        1
    );
#endif
}

void stack_usage() {
    // prints out information about current stack usage
    struct rlimit l;
    int r = getrlimit(RLIMIT_STACK, &l);
    if (r != 0) abort();
    void * rp = &r;
    if (rp > stack_end) read_maps(1);
    size_t used = (size_t) (stack_end - rp);
    size_t max = l.rlim_cur;
    double pct = (((double) used) / ((double) max)) * 100.0;
    debug(
        "Currently mapped %zu bytes of stack out of a maximum of %zu\n",
        (size_t) (stack_end - stack_start),
           max
          );
    printf(
        "Currently using about %zu bytes of stack, out of a maximum of %zu bytes: %.0f%%\n",
        used,
        max,
        pct
    );
}

// Example variables -----------
int global_scalar;
const int global_const_scalar = 789;

int global_array[N][N];

const int global_const_array[N][N] = {
    { 0, 1, 2, 3, 4 },
    { 5, 6, 7, 8, 9 },
    { 10, 11, 12, 13, 14 },
    { 15, 16, 17, 18, 19 },
    { 20, 21, 22, 23, 24 }
};

int initialized_global_array[N][N] = {
    { 0, 1, 2, 3, 4 },
    { 5, 6, 7, 8, 9 },
    { 10, 11, 12, 13, 14 },
    { 15, 16, 17, 18, 19 },
    { 20, 21, 22, 23, 24 }
};

const char * const_char_p = "pointer to constant char";
const char * const const_char_p_const = "constant pointer to constant char";

void g() {
    char one_megabyte[1024][1024];
    DESCRIBE(one_megabyte);
    stack_usage();
    return;
} 

void f() {
    int f_local = 7;
    DESCRIBE(f_local);
    stack_usage();
    g();
}

int main(int argc, char **argv) {
    int local_array[N][N];
    char local_string[] = "local string";
    static int static_local;
    const int const_local = 123;
    static const int static_const_local = 456;
    int *heap_array = malloc(N * N * sizeof(int));
    int *huge_array = malloc(1024 * 1024 * sizeof(int));
    
    layout();
    DESCRIBE(global_scalar);
    DESCRIBE(global_array);
    DESCRIBE(global_const_scalar);
    DESCRIBE(global_const_array);
    DESCRIBE(initialized_global_array);
    DESCRIBE(const_char_p);
    printf("    (the pointer itself can be changed!)\n");
    DESCRIBE(*const_char_p);
    printf("    (we have no array size information because we went through a pointer!)\n");
    DESCRIBE(const_char_p_const);
    DESCRIBE("string literal");
    DESCRIBE(local_array);
    DESCRIBE(local_string);
    DESCRIBE(static_local);
    DESCRIBE(const_local);
    DESCRIBE(static_const_local);
    DESCRIBE(heap_array[0]);
    DESCRIBE(huge_array[0]);
    DESCRIBE(f);
    f();
    free(heap_array);
    free(huge_array);
    free_maps();
}
