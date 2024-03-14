#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "qformat.h"

int main(int argc, char* argv[])
{
    unsigned int bits, encode;
    int q_value;
    double f_value;

    if (argc < 4)
        return -1;

    bits = atoi(argv[1]);
    encode = atoi(argv[2]);

    if (encode) {
        f_value = atof(argv[3]);

        if (q_encode(bits, f_value, &q_value)) {
            fprintf(stderr, "float out of range\n");
            return -1;
        }
    } else {
        q_value = atoi(argv[3]);
        f_value = q_decode(bits, q_value);
    }

    printf("min/max: %.20f / %.20f\n", q_decode(bits, INT_MIN),
        q_decode(bits, INT_MAX));
    printf("\n");
    printf("Q%d value: %d [0x%08x] - float %.20f\n", bits, q_value, q_value,
        f_value);
    return 0;
}
