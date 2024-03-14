#pragma once

double q_decode(unsigned int bits, int q_value);
int q_encode(unsigned int bits, double f_value, int* q_value_p);
