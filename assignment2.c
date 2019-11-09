#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UP
#define UP '^' // value came from the element above (row-1,col)
#define LEFT '<' // value came from the element to the left (row-1,col)
#define DIAG '\\' // value came from the element above and to the left (row-1,col-1)
#define COMMON '+' // value came from the element above and to the left, plus 1 because the strings had something in common
#define BORDER '*' // value is on the border, either row=0 or col=0
#define UNINIT '?' // value is uninitialized
#endif /* UP */

const char *alphabet = "acgt";
size_t alphabet_size = 4;

#ifdef SHOW_WORK
#define printw(...) fprintf(stderr, __VA_ARGS__)
#else
#define printw(...)
#endif

#ifdef SHOW_PROGRESS
#define printp(...) fprintf(stderr, __VA_ARGS__)
#else
#define printp(...)
#endif

#define printe(...) fprintf(stderr, __VA_ARGS__)

struct matrix {
    char *rs; // row string
    char *cs; // column string
    size_t rs_len; // strlen(rs)
    size_t cs_len; // strlen(cs)
    size_t *data; // values of the matrix
    char *path; // where the value came from
};

size_t rows(struct matrix *m) {
    // Returns # of rows in the matrix
    return m->rs_len + 1;
}

size_t cols(struct matrix *m) {
    // Returns # of cols in the matrix
    return m->cs_len + 1;
}

struct cursor {
    struct matrix *m; // What matrix we're referring to
    size_t row; // which row in m
    size_t col; // which column in m
};

size_t ij(struct cursor c) {
    // compute the 1-d array element coresponding to matrix element (row,col)
    size_t cols = c.m->cs_len + 1;
    return c.row * cols + c.col;
}

int in(struct cursor *c) {
    // returns true iff the cursor is inside of the matrix
    if (!(c->row < rows(c->m))) return 0;
    if (!(c->col < cols(c->m))) return 0;
//     if (row < 0) return 0;
//     if (col < 0) return 0;
    return 1;
}

struct cursor new_cursor(
    struct matrix *m,
    size_t row,
    size_t col
) {
    // constructs a new cursor
    struct cursor new = {m, row, col};
    if(!in(&new)) abort();
    return new;
}

void set(
    struct cursor c,
    size_t value, // value for element
    char direction // where the value came from
          ) {
    // sets a matrix value and path information
    if(!in(&c)) abort();
    c.m->data[ij(c)] = value;
    c.m->path[ij(c)] = direction;
}

struct cursor zerozero(struct matrix *m) {
    // constructs a new cursor at element (0,0) of matrix
    return new_cursor(m, 0, 0);
}

void right(struct cursor *c) {
    // moves cursor one element to the right
    c->col += 1;
}

void down(struct cursor *c) {
    // moves cursor one element down
    c->row += 1;
}

void left(struct cursor *c) {
    // moves cursor one element left
    c->col -= 1;
}

void up(struct cursor *c) {
    // moves cursor one element up
    c->row -= 1;
}

struct cursor up_from(struct cursor c) {
    // constructs a new cursor, one element up from a given cursor
    struct cursor new = c;
    up(&new);
    return new;
}

struct cursor left_from(struct cursor c) {
    // constructs a new cursor, one element left from a given cursor
    struct cursor new = c;
    left(&new);
    return new;
}

void next(struct cursor *c) {
    // moves cursor to the next element
    // either the next element in the column,
    // or if at end of column,
    // the first element of the next row
    right(c);
    if (!in(c)) {
        down(c);
        c->col = 0;
    }
}

void reset(struct matrix *m) {
    // resets a matrix to be uninitialized
    for (struct cursor c = zerozero(m);
         in(&c);
         next(&c)
    ) {
        set(c, 0, UNINIT);
    }
}

struct matrix new_matrix(char *rs, char *cs) {
    // constructs a new matrix for two given strings
    size_t rs_len = strlen(rs);
    size_t cs_len = strlen(cs);
    size_t rows = rs_len + 1;
    size_t cols = cs_len + 1;
    size_t *data =
        malloc(rows * cols * sizeof(size_t));
    char *path = malloc(rows * cols * sizeof(char));
    struct matrix new = {rs, cs, rs_len, cs_len, data, path};
    reset(&new);
    return new;
}

size_t direction(struct cursor c) {
    // gets the direction of the element at the cursor
    if (!in(&c)) abort();
    return c.m->path[ij(c)];
}

void debug_cursor(struct cursor c) {
    printe("[%zu of %zu][%zu of %zu]",
           c.row,
           rows(c.m),
           c.col,
           cols(c.m)
    );
    if (in(&c)) {
        printe(" = %zu %c\n",
            c.m->data[ij(c)],
            c.m->path[ij(c)]
        );
    } else {
        printf("\n");
    }
}

void cursor_abort(struct cursor c) {
    printe("Bad: ");
    debug_cursor(c);
    abort();
}

size_t get(struct cursor c) {
    // gets the value of the element at the cursor
    if (!in(&c)) cursor_abort(c);
    if (direction(c) == UNINIT)
        cursor_abort(c);
    return c.m->data[ij(c)];
}

char rs_last(struct cursor c) {
    // gets the last character of the row string, if the row string was only c.row elements long
    if (c.row < 1) abort();
    return c.m->rs[c.row-1];
}

char cs_last(struct cursor c) {
    // gets the last character of the columns string, if the columns string was only c.col elements long
    if (c.col < 1) abort();
    return c.m->cs[c.col-1];
}

struct cursor last(struct matrix *m) {
    // returns a cursor a the last element of m
    return new_cursor(m,
                      m->rs_len,
                      m->cs_len
           );
}

size_t fill_matrix(struct matrix *m) {
    for (struct cursor c = zerozero(m);
         in(&c);
         next(&c)
    ) {
        if (direction(c) != UNINIT) abort();
        if (c.row == 0 || c.col == 0) {
            set(c, 0, BORDER);
            continue;
        }
        // We're not on row 0 or column 0 so do the computation
        size_t up_value = get(up_from(c));
        size_t left_value = get(left_from(c));
        size_t diag_value =
            get(left_from(up_from(c)));
        char diag_direction = DIAG;
        if (rs_last(c) == cs_last(c)) {
            // there's a character in common between rs and cs here
            // so we can potentially add it to our LCS
            // recorded by increasing the value along the diagonal
            diag_value += 1;
            diag_direction = COMMON;
        }
        if (up_value >= left_value
            && up_value >= diag_value
        ) {
            // up is the best
            set(c, up_value, UP);
        } else if (
            left_value >= up_value
            && left_value >= diag_value
               ) {
            // left is the best
            set(c, left_value, LEFT);
        } else if (
            diag_value >= up_value
            && diag_value >= left_value
               ) {
            // diag is the best
            // (maybe with bonus from having a character in common)
            set(
                c,
                diag_value,
                diag_direction
            );
        } else {
            printe("%zu %zu %zu\n",
                up_value,
                left_value,
                diag_value
            );
            abort(); // This shouldn't happen!
        }
    }
    return get(last(m));
}

void debug_matrix(struct matrix *m) {
    for (size_t i = 0; i < rows(m); i++) {
        for (size_t j = 0; j < cols(m); j++) {
            struct cursor c = new_cursor(m, i, j);
            printe("%3zu", get(c));
        }
        printe("\n");
    }
}

void follow(struct cursor *c) {
    // follows the path backwards, one step at a time!
    if (direction(*c) == UP) {
        up(c);
    } else if (direction(*c) == LEFT) {
        left(c);
    } else if (
        direction(*c) == DIAG
        || direction(*c) == COMMON
    ) {
        up(c);
        left(c);
    } else if (direction(*c) == BORDER) {
        // we're done
        c->row = -1;
        c->col = -1;
    } else {
        abort();
    }
}

void reverse_in_place(char * s) {
    size_t n = strlen(s);
    for (size_t i = 0; i < n/2; i++) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

char * unwind(
    struct matrix *m
) {
    // retrieves the LCS from the matrix
    size_t len = get(last(m));
    char *lcs = malloc((len+1) * sizeof(char));
    size_t i = 0; // index into lcs
    for (struct cursor c = last(m);
         in(&c);
         follow(&c)
    ) {
        if (direction(c) == COMMON) {
            if (rs_last(c) != cs_last(c)) {
                abort();
            }
            lcs[i] = rs_last(c);
            i += 1;
        }
    }
    if (i != len) abort();
    lcs[i] = '\0';
    reverse_in_place(lcs);
    return lcs;
}

char * genseq(size_t n) {
    char *s = (char *) 
        malloc((n+1) * sizeof(char));
    for (size_t i = 0; i < n; i++) {
        s[i] = alphabet[rand() % alphabet_size];
    }
    s[n] = '\0';
    return s;
}

char *reverse_copy(
    char *s
) {
    size_t n = strlen(s);
    char * r = malloc((n+1) * sizeof(char));
    for (size_t i = 0; i < n; i++) {
        r[n-i-1] = s[i];
    }
    r[n] = '\0';
    return r;
}

void free_matrix(struct matrix *m) {
    free(m->data);
    free(m->path);
    m->data = NULL;
    m->path = NULL;
}

int check_ss(char *s, char *ss) {
    printw("Is it a subsequence?\n");
    printw("%s\n", s);
    size_t s_len = strlen(s);
    size_t ss_len = strlen(ss);
    if (ss_len > s_len) abort();
    size_t j = 0; // index into s
    for (size_t i = 0; i < ss_len; i++) {
        while (s[j] != ss[i]) {
            printw(" ");
            j++;
            if (j >= s_len) {
                abort();
            }
        }
        printw("%c", ss[i]);
        j++;
    }
    printw("\n");
    printw("Yes.\n");
    return 1;
}

int check_lps(char *s, char *ss) {
    printw("Is it a palindrome?\n");
    size_t ss_len = strlen(ss);
    printw("%s\n", ss);
    // check if it's a palindrome
    for (size_t i = 0; i < ss_len; i++) {
        printw("%c", ss[ss_len-i-1]);
        if (ss[i] != ss[ss_len-i-1]) {
            abort();
        }
    }
    printw("\n");
    printw("Yes.\n");
    // check if its a subsequence
    return check_ss(s, ss);
}

void palindromeize(char *ss) {
    size_t ss_len = strlen(ss);
    for (size_t i = 0; i < ss_len/2; i++) {
        ss[ss_len-i-1] = ss[i];
    }
}

char * lps(char *s) {
    printp("LPS computation ----------\n");
    char * sr = reverse_copy(s);
    printw("Sequence: %s\n", s);
    printw("Reversed: %s\n", sr);
    struct matrix m = new_matrix(s, sr);
    size_t lps_len = fill_matrix(&m);
    (void) lps_len;
    printw("LPS length: %zu\n", lps_len);
    char * ss = unwind(&m);
    palindromeize(ss);
    printw("LPS: %s\n", ss);
    check_lps(s, ss);
    free(sr);
    free_matrix(&m);
    return ss;
}

char *make_substring(
    char *s,
    size_t start,
    size_t len
) {
    size_t original_len = strlen(s);
    if (start + len > original_len) {
        printe("Original length: %zu, requested start: %zu, requested len: %zu\n",
               original_len,
               start,
               len);
        abort();
    }
    char *ss = malloc((len+1) * sizeof(char));
    strncpy(
        ss, // dest
        s + start, // src
        len); // n
    ss[len] = '\0';
    return ss;
}

struct maxhts {
    char *s; // the sequence
    size_t n; // length of the sequence
    size_t *l; // max lengths of hts if split at l[i]
    int *known; // whether the length is known for sure or a max
    size_t max_known;
    char * max_hts;
    size_t max_left_len;
    char **hts; // hts sequences for each length
    size_t biggest_unknown;
    int done;
};

void base_maxhts(
    struct maxhts *mh,
    size_t left_len
) {
    size_t total = 0;
    for (size_t ai = 0; ai < alphabet_size; ai++) {
        char c = alphabet[ai];
        size_t left_count = 0;
        size_t right_count = 0;
        for (size_t i = 0; i < mh->n; i++) {
            if (mh->s[i] == c) {
                if (i < left_len) {
                    left_count++;
                } else {
                    right_count++;
                }
            }
        }
        size_t min_count = 0;
        if (left_count < right_count) {
            min_count = left_count;
        } else {
            min_count = right_count;
        }
        total += min_count;
    }
    if (total > 0) {
        mh->l[left_len] = total;
        mh->known[left_len] = 0;
        mh->hts[left_len] = NULL;
    } else {
        mh->l[left_len] = total;
        mh->known[left_len] = 1;
        mh->hts[left_len] = malloc(1 * sizeof(char));
        mh->hts[left_len][0] = '\0';
    }
}

struct maxhts new_maxhts(char *s) {
    size_t n = strlen(s);
    size_t *m = 
        malloc((n+1) * sizeof(size_t));
    struct maxhts mh = {
        s,
        n,
        m,
        malloc((n+1) * sizeof(int)),
        0,
        NULL,
        0,
        malloc((n+1) * sizeof(char *)),
        0,
        0
    };
    for (size_t left_len = 0;
         left_len < (n+1);
         left_len++
    ) {
        base_maxhts(&mh, left_len);
    }
    mh.max_hts = mh.hts[0];
    return mh;
}

void free_maxhts(struct maxhts *mh) {
    size_t n = mh->n;
    mh->n = 0;
    free(mh->l);
    mh->l = NULL;
    free(mh->known);
    mh->known = NULL;
    for (size_t i = 0; i < (n+1); i++) {
        char *hts = mh->hts[i];
        if (hts != NULL) {
            free(hts);
        }
    }
    mh->max_hts = NULL;
    free(mh->hts);
    mh->hts = NULL;
    mh->biggest_unknown = 0;
}

void print_maxhts(struct maxhts *mh) {
#ifdef SHOW_WORK
    printw("left_len know hts_len half_tandem_subsequence\n");
    for (size_t left_len = 0;
         left_len < (mh->n+1);
         left_len++
    ) {
        char *le = "<=";
        char *eq = "==";
        char *op;
        char *unknown = "???";
        char *wont = "";
        char *hts;
        if (mh->known[left_len]) {
            op = eq;
            hts = mh->hts[left_len];
        } else {
            op = le;
            if (mh->l[left_len] > mh->max_known) {
                hts = unknown;
            } else {
                hts = wont;
            }
        }
        printw("%8zu %4s %7zu %s ",
            left_len,
            op,
            mh->l[left_len],
            hts
        );
        if (left_len == mh->max_left_len
            && !mh->done
        ) {
            printw("<- biggest known");
        }
        if (left_len == mh->max_left_len
            && mh->done
        ) {
            printw("<- lts");
        }
        if (left_len == mh->biggest_unknown
            && !mh->done
        ) {
            printw("<- biggest unknown");
        }
        printw("\n");
    }
#endif /* SHOW_WORK */
}

void find_biggest_unknown(struct maxhts *mh) {
    size_t biggest = 0;
    size_t remaining = 0;
    for (size_t left_len = 0;
         left_len < (mh->n+1);
         left_len++
    ) {
        if (
            (mh->l[left_len] 
                > mh->l[biggest])
            && (!mh->known[left_len])) {
            biggest = left_len;
        }
        if (
            (mh->l[left_len] 
                > mh->max_known)
            && (!mh->known[left_len])
        ) {
            remaining++;
        }
    }
    if (mh->l[biggest] <= mh->max_known) {
        mh->biggest_unknown = 0;
        mh->done = 1;
        if (remaining != 0) {
            printe("biggest l[%zu]=%zu\n",
                biggest,
                mh->l[biggest]
            );
            printe("%zu remaining\n", remaining);
            print_maxhts(mh);
            abort();
        }
    } else {
        mh->biggest_unknown = biggest;
        mh->done = 0;
    }
    printp("%zu remaining\n", remaining);
}

void propagate_knowledge(
    struct maxhts *mh,
    size_t left_len
     ) {
    if (!mh->known[left_len]) abort();
    size_t knowledge = mh->l[left_len];
    size_t updated = 0;
    for (size_t i = left_len-1;
         i > 0;
         i--
    ) {
        size_t dist = left_len - i;
        size_t max = knowledge + dist;
        if (mh->l[i] > max) {
            if (mh->known[i]) abort();
            printw(
                "%zu had a max of %zu but it is only %zu before %zu which is known to be %zu, so %zu can only have a max of %zu\n",
                i,
                mh->l[i],
                dist,
                left_len,
                knowledge,
                i,
                max
            );
            mh->l[i] = max;
            updated++;
        }
    }
    for (size_t i = left_len+1;
         i < (mh->n+1);
         i++
    ) {
        size_t dist = i - left_len;
        size_t max = knowledge + dist;
        if (mh->l[i] > max) {
            if (mh->known[i]) abort();
            printw(
                "%zu had a max of %zu but it is only %zu after %zu which is known to be %zu, so %zu can only have a max of %zu\n",
                i,
                mh->l[i],
                dist,
                left_len,
                knowledge,
                i,
                max
            );
            mh->l[i] = max;
            updated++;
        }
    }
    printp("Knowledge propagated to %zu items\n", updated); 
}

void compute_hts(
    struct maxhts *mh,
    size_t left_len
) {
    if (mh->known[left_len]) abort();
    char *left = make_substring(
        mh->s,
        0,
        left_len
    );
    char *right = make_substring(
        mh->s,
        left_len,
        mh->n - left_len
    );
    if (mh->known[left_len]) abort();
    printw("Split: %s|%s\n", left, right);
    struct matrix m = new_matrix(left, right);
    size_t hts_len = fill_matrix(&m);
    char * hts = unwind(&m);
    printp("half tandem subsequence length %zu\n", hts_len);
    printw("HTS: %s\n", hts);
    if (hts_len > mh->l[left_len])
        abort();
    mh->l[left_len] = hts_len;
    mh->known[left_len] = 1;
    mh->hts[left_len] = hts;
    if (hts_len > mh->max_known) {
        mh->max_left_len = left_len;
        mh->max_hts = hts;
        mh->max_known = hts_len;
    }
    free(left);
    free(right);
    free_matrix(&m);
}

char * lts(char *s) {
    printp("LTS computation ----------\n");
    struct maxhts mh = new_maxhts(s);
    find_biggest_unknown(&mh);
    printw("Initially:\n");
    print_maxhts(&mh);
    size_t computations = 0;
    while (!mh.done) {
        size_t left_len =
            mh.biggest_unknown;
        printp("LCS computation %zu: left_len=%zu\n",
               computations,
               left_len);
        compute_hts(&mh, left_len);
        computations++;
        propagate_knowledge(&mh, left_len);
        find_biggest_unknown(&mh);
        print_maxhts(&mh);
    };
    printp("Computations: %zu\n", computations);
    printp("Best split: %zu\n",
        mh.max_left_len
    );
    printp("Best length: %zu\n",
        mh.max_known
    );
    printw("Longest half-tandem subsequence: %s\n",
        mh.max_hts
    );
    char * ltsr = malloc(
        (mh.max_known*2+1) * sizeof(char)
                 );
    strcpy(ltsr, mh.max_hts);
    strcpy(ltsr+mh.max_known, mh.max_hts);
    check_ss(s, ltsr);
    free_maxhts(&mh);
    return ltsr;
}

int try_read(char *name, char **ps) {
    printf("enter the %s sequence: ", name);
    int r = scanf("%m[^\n]", ps);
    char c;
    int nl = scanf("%c", &c);
    if (r == 1 && nl == 1 && c == '\n') {
        return 1;
    } else {
        printe("Didn't scanf :(\n");
        return 0;
    }
}

int prompt(char **first, char **second) {
//     printf("To compute an LCS,\n");
    int a = try_read("first", first);
    int b = try_read("second", second);
    return a && b;
}

int char_in_alphabet(char c) {
    for (size_t i = 0; i < alphabet_size; i++) {
        if (c == alphabet[i]) {
            return 1;
        }
    }
    return 0;
}

int valid(char *s) {
    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++) {
        if (!char_in_alphabet(s[i])) {
            return 0;
        }
    }
    return 1;
}

/*
3110283025318292818318143
13112301728031631251841324
*/

void assignment() {
    alphabet = "0123456789";
    alphabet_size = 10;
    char *first;
    char *second;
    while (
        (!prompt(&first, &second))
        || (!valid(first))
        || (!valid(second))
      ) {
        printf("Error, non-digit character detected!\n\n");
    }
    printf("# Two input sequences (length = %zu, %zu) are:\n", strlen(first), strlen(second));
    printf("%s\n", first);
    printf("%s\n", second);
    // lcs(first, second);
    char *result = lts(first);
    printf("# an LTS (length = %zu) for the first sequence is:\n",  
           strlen(result)
    );
    printf("%s\n", result);
    free(result);
    result = lps(second);
    printf("# an LPS (length = %zu) for the second sequence is:\n", 
           strlen(result)
    );
    printf("%s\n", result);
    free(result);
    free(first);
    free(second);
}

void generated(size_t n) {
    char * a = genseq(n);
    printf("Sequence: %s\n", a);
    char * result = lps(a);
    printf("LPS: %s\n", result);
    free(result);
    result = lts(a);
    printf("LTS: %s\n", result);
    free(result);
    free(a);
}

int main(int argc, char **argv) {
    size_t n;
    if (argc < 2 || sscanf(argv[1], "%zu", &n) != 1) {
        assignment();
    } else {
        if (argc >= 3) {
            alphabet = argv[2];
            alphabet_size = strlen(alphabet);
        }
        generated(n);
    }
    return 0;
}
