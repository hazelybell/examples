# we use -c to do a partial compilation
# and we store the result in a .o file
# (object file)

# the final compilation step "links" all the object files together to form the final executable program

gcc --std=c99 -Wall -ftrapv -ggdb -DDEBUG -c -o matrix.o matrix.c && \
gcc --std=c99 -Wall -ftrapv -ggdb -DDEBUG -c -o matrix_io.o matrix_io.c && \
gcc --std=c99 -Wall -ftrapv -ggdb -DDEBUG -c -o matrix_ops.o matrix_ops.c && \
gcc --std=c99 -Wall -ftrapv -ggdb -DDEBUG -c -o debugging.o debugging.c && \
gcc --std=c99 -Wall -ftrapv -ggdb -DDEBUG -c -o matrix_split.o matrix_split.c && \
gcc --std=c99 -Wall -ftrapv -ggdb -DDEBUG -o matrix_split matrix_split.o matrix.o matrix_io.o matrix_ops.o debugging.o && \
./matrix_split <../two_matrices_1.txt

