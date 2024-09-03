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
    f_value *= (1 << bits);

    // +-0.5 for rounding
    f_value += f_value > 0 ? 0.5 : -0.5;

    if (f_value < (double)INT_MIN || f_value > (double)INT_MAX)
        return -ERANGE;

    *q_value_p = (int)(f_value);
    return 0;
}
