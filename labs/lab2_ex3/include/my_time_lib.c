#include <math.h>

// mean
double mu_fn(double *values, int len) {
    double mean = 0;
    for (int i = 0; i < len; i++)
        mean += values[i];

    return mean / len;
}

// variance
double sigma_fn(double *values, double mean, int len) {
    double variance = 0;
    for (int i = 0; i < len; i++)
        variance += pow(values[i] - mean, 2);

    return variance / len;
}
