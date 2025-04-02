#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define NPROBS 8

#define LEN 15
#define N 5
#define M 5

#define PRINT_RESULT_VECTOR(V, NAME)                                           \
    {                                                                          \
        printf("%2s: ", NAME);                                                 \
        for (int i = 0; i < LEN; i++)                                          \
            printf("%4d ", V[i]);                                              \
        printf("\n");                                                          \
    }

#define PRINT_RESULT_MATRIX(MAT, NAME)                                         \
    {                                                                          \
        printf("%2s matrix:\n\t", NAME);                                       \
        for (int i = 0; i < N; i++) {                                          \
            for (int j = 0; j < M; j++)                                        \
                printf("%4d ", MAT[i * M + j]);                                \
            printf("\n\t");                                                    \
        }                                                                      \
        printf("\n");                                                          \
    }

// -------- uncomment these two lines when solutions are published --------
// #include "solutions/stack_n_heap_solutions.c"
// #define RESULTS
// ------------------------------------------------------------------------

#ifndef SOLUTION_STACKVEC_1
#define SOLUTION_STACKVEC_1                                                    \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_HEAPVEC_1
#define SOLUTION_HEAPVEC_1                                                     \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_HEAPVEC_2
#define SOLUTION_HEAPVEC_2                                                     \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_STACKVEC_2
#define SOLUTION_STACKVEC_2                                                    \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_STACKMAT_1
#define SOLUTION_STACKMAT_1                                                    \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_HEAPMAT_1
#define SOLUTION_HEAPMAT_1                                                     \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_HEAPMAT_2
#define SOLUTION_HEAPMAT_2                                                     \
    {                                                                          \
    }
#endif

#ifndef SOLUTION_STACKMAT_2
#define SOLUTION_STACKMAT_2                                                    \
    {                                                                          \
    }
#endif

void alloced_heap_vec(int *a, int *b, int *c, int len) {
    for (int i = 0; i < len; i++)
        c[i] = a[i] + b[i];
}

void not_alloced_heap_vec(int *a, int *b, int **c, int len) {
    *c = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
        (*c)[i] = a[i] + b[i];
}

void alloced_heap_mat(int *a, int *b, int n, int m, int *c) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c[i * m + j] = a[i * m + j] + b[i * m + j];
}

void not_alloced_heap_mat(int *a, int *b, int n, int m, int **c) {
    *c = malloc(sizeof(int) * n * m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            (*c)[i * m + j] = a[i * m + j] + b[i * m + j];
}

int main(void) {
    // ---------- for timing ----------
    float CPU_times[NPROBS];
    for (int i = 0; i < NPROBS; i++)
        CPU_times[i] = 0.0;
    struct timeval temp_1, temp_2;
    // --------------------------------

#ifdef RESULTS
    printf("You are now running the \x1B[31mSOLUTION CODE\x1B[37m:\n");
#else
    printf("You are now running \x1B[31mYOUR CODE\x1B[37m:\n");
#endif
    // ---------------------- Stack vectors 1 ----------------------
    /* Generate three stack vectors a, and b of length "LEN" such
     * that for each i in {0, 1, ... LEN-1} a[i] = i, b[i] = 100 * i.
     * Then compute the vector c = a + b.
     */

#ifdef RESULTS
    SOLUTION_STACKVEC_1
    PRINT_RESULT_VECTOR(c, "c")
#else
    gettimeofday(&temp_1, (struct timezone *)0);

    int a[LEN], b[LEN], c[LEN];
    for (int i = 0; i < LEN; i++) {
        a[i] = i;
        b[i] = 100 * i;
    }
    for (int i = 0; i < LEN; i++)
        c[i] = a[i] + b[i];

    gettimeofday(&temp_2, (struct timezone *)0);
    CPU_times[0] = ((temp_2.tv_sec - temp_1.tv_sec) +
                    (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0);
    PRINT_RESULT_VECTOR(c, "c")

#endif
    // ---------------------- Heap vectors 1 -----------------------
    /* Compute the same result as c but in a heap vector c1 allocated
     * in the main but computed in a function out of the main.
     */
#ifdef RESULTS
    SOLUTION_HEAPVEC_1
    PRINT_RESULT_VECTOR(c1, "c1")
#else
    gettimeofday(&temp_1, (struct timezone *)0);

    int *c1 = malloc(sizeof(int) * LEN);
    alloced_heap_vec(a, b, c1, LEN);

    gettimeofday(&temp_2, (struct timezone *)0);
    CPU_times[0] = ((temp_2.tv_sec - temp_1.tv_sec) +
                    (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0);
    PRINT_RESULT_VECTOR(c1, "c1")
    free(c1);

#endif
    // ---------------------- Heap vectors 2 -----------------------
    /* Compute the same result as c and c1 in a heap vector c2
     * which, this time, is allocated in the function out of the main
     */
#ifdef RESULTS
    SOLUTION_HEAPVEC_2
    PRINT_RESULT_VECTOR(c2, "c2")
#else
    gettimeofday(&temp_1, (struct timezone *)0);

    int *c2;
    not_alloced_heap_vec(a, b, &c2, LEN);

    gettimeofday(&temp_2, (struct timezone *)0);
    CPU_times[0] = ((temp_2.tv_sec - temp_1.tv_sec) +
                    (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0);
    PRINT_RESULT_VECTOR(c2, "c2")

#endif
    // ---------------------- Stack vectors 2 ----------------------
    /* Is it possible to compute the c vector as a stack vector of
     * the out-main function and then return it to the main?
     */
#ifdef RESULTS
    SOLUTION_STACKVEC_2
#else
    printf("No\n");

#endif

    /* Now, do the same 4 previous exercises but with the three
     * matrices A, B, C. All the matrices has N rows and M columns.
     * Moreover:
     *   1) A[i][j] = i + j
     *   2) B[i][j] = (i + j) * 100
     *   3) C = A + B
     *
     * What are the differences when you change from vectors to
     * matrices?
     */
    // --------------------- Stack matrices ----------------------
#ifdef RESULTS
    SOLUTION_STACKMAT_1
    PRINT_RESULT_MATRIX(((int *)C), "C")
#else
    gettimeofday(&temp_1, (struct timezone *)0);

    int A[N][M], B[N][M], C[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = i + j;
            B[i][j] = (i + j) * 100;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            C[i][j] = A[i][j] + B[i][j];

    gettimeofday(&temp_2, (struct timezone *)0);
    CPU_times[0] = ((temp_2.tv_sec - temp_1.tv_sec) +
                    (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0);
    PRINT_RESULT_MATRIX(((int *)C), "C")

#endif

    // --------------------- Heap matrices -----------------------
#ifdef RESULTS
    SOLUTION_HEAPMAT_1
    PRINT_RESULT_MATRIX(C1, "C1")
#else
    gettimeofday(&temp_1, (struct timezone *)0);

    int *C1 = malloc(sizeof(int) * N * M);
    alloced_heap_mat((int *)A, (int *)B, N, M, C1);
    PRINT_RESULT_MATRIX(C1, "C1")

    gettimeofday(&temp_2, (struct timezone *)0);
    CPU_times[0] = ((temp_2.tv_sec - temp_1.tv_sec) +
                    (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0);

#endif

    // --------------------- Heap matrices -----------------------
#ifdef RESULTS
    SOLUTION_HEAPMAT_2
    PRINT_RESULT_MATRIX(C2, "C2")
#else
    gettimeofday(&temp_1, (struct timezone *)0);

    int *C2;
    not_alloced_heap_mat((int *)A, (int *)B, N, M, &C2);
    PRINT_RESULT_MATRIX(C2, "C2")

    gettimeofday(&temp_2, (struct timezone *)0);
    CPU_times[0] = ((temp_2.tv_sec - temp_1.tv_sec) +
                    (temp_2.tv_usec - temp_1.tv_usec) / 1000000.0);

#endif

    // --------------------- Stack matrices ----------------------
#ifdef RESULTS
    SOLUTION_STACKMAT_2
#else
    printf("No\n");

#endif

    for (int i = 0; i < NPROBS; i++) {
        printf("Problem %d runs in %9.8f CPU time\n", i, CPU_times[i]);
    }
    printf("\n");

    return (0);
}
