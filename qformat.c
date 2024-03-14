#include "qformat.h"

#include <errno.h>
#include <limits.h>
#include <stdint.h>

double q_decode(unsigned int bits, int q_value)
{
    return (double)q_value / (1 << bits);
}

int q_encode(unsigned int bits, double f_value, int* q_value_p)
{
    static const double max = (double)INT_MAX;
    static const double min = (double)INT_MIN;

    f_value *= (1 << bits);

    if (f_value < min || f_value > max)
        return -ERANGE;

    // +-0.5 for rounding
    *q_value_p = (int)(f_value + (f_value > 0 ? 0.5 : -0.5));
    return 0;
}
