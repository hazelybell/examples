# all the compiler options that are the same
CFLAGS="--std=c99 -Wall -ftrapv -ggdb -DDEBUG"

gcc $CFLAGS -c -o matrix.o matrix.c && \
gcc $CFLAGS -c -o matrix_io.o matrix_io.c && \
gcc $CFLAGS -c -o matrix_ops.o matrix_ops.c && \
gcc $CFLAGS -c -o debugging.o debugging.c && \
gcc $CFLAGS -c -o matrix_split.o matrix_split.c && \
gcc $CFLAGS -o matrix_split matrix_split.o matrix.o matrix_io.o matrix_ops.o debugging.o && \
./matrix_split <../two_matrices_1.txt

