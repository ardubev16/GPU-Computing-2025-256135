#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #define DOUBLE
#ifdef DOUBLE
#define dtype double
#else
#define dtype int
#endif /* ifdef DOUBLE */

#define NITER 10

#include "include/my_time_lib.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s n\n", argv[0]);
        return (1);
    }

    printf("argv[0] = %s\n", argv[1]);

    TIMER_DEF(0);
    int n = atoi(argv[1]);
    dtype *a, *b, c;
    double times[NITER];
    int len = 1 << n;

    fprintf(stdout, "dtype = %s\n", XSTR(dtype));
    fprintf(stdout, "n = %d, len = %d\n", n, len);

    fprintf(stdout, "Allocating memory... ");
    fflush(stdout);

    TIMER_START(0);
    a = malloc(sizeof(dtype) * len);
    b = malloc(sizeof(dtype) * len);
    TIMER_STOP(0);

    fprintf(stdout, "done in %lfs\n", TIMER_ELAPSED(0) / 1.e6);

    fprintf(stdout, "Generating input vectors... ");
    fflush(stdout);

    TIMER_START(0);
    srand(time(NULL));
#ifdef DOUBLE
    for (int i = 0; i < len; i++) {
        a[i] = (double)rand() / ((double)RAND_MAX);
        b[i] = (double)rand() / ((double)RAND_MAX);
    }
#else
    for (int i = 0; i < len; i++) {
        a[i] = rand() / (1 << 11);
        b[i] = rand() / (1 << 11);
    }
#endif /* ifdef DOUBLE */
    TIMER_STOP(0);

    fprintf(stdout, "done in %lfs\n", TIMER_ELAPSED(0) / 1.e6);

    fprintf(stdout, "\n\nPerforming scalar product...\n");
    fflush(stdout);

    for (int i = -2; i < NITER; i++) {
        TIMER_START(0);
        c = 0;
        for (int j = 0; j < len; j++) {
            c += a[j] * b[j];
        }
        TIMER_STOP(0);

        double iter_time = TIMER_ELAPSED(0);
        if (i >= 0)
            times[i] = iter_time;

        printf("%d - Iter %d took %lfs\n", c, i, iter_time);
    }
    fprintf(stdout, "%d iterations performed\n\n", NITER);

    double mu = mu_fn(times, NITER);
    double sigma = sigma_fn(times, mu, NITER);

    printf(" %10s | %10s | %10s |\n", "v name", "mu(v)", "sigma(v)");
    printf(" %10s | %10f | %10f |\n", "time", mu, sigma);

    // NOTE: LEN multiplications + LEN - 1 additions
    int nflop = 2 * len - 1;
    fprintf(stdout,
            "\nEach scalar produce required 2 * len - 1 = %d floating point "
            "operations.\n",
            nflop);

    double flops = nflop / mu;
    fprintf(stdout, "The scalar product achieved %lf MFLOP/s\n", flops / 1.e6);

    return 0;
}
