#include <stdio.h>
#include <unistd.h>

int real_main(int argc, char ** argv) {
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
        setsid();
        sleep(100);
}

int main(int argc, char ** argv) {
    if (fork() == 0) {
        return real_main(argc, char ** argv);
    }
    return 0;
}
