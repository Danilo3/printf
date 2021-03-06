//
// Created by Aletha Yellin on 26/12/2019.
//

#include "libft.h"

unsigned int    count_bits(unsigned long n)
{
    unsigned int i;

    i = 0;
    while (n)
    {
        i++;
        n >>= 1;
    }
    return (i);
}

unsigned long bin_to_dec(unsigned long b)
{
    unsigned long   dec_value;
    int             base;
    unsigned long   temp;
    unsigned long   last_digit;

    dec_value = 0;
    base = 1;
    temp = b;
    while (temp)
    {
        last_digit = temp % 2;
        temp = temp / 2;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return (dec_value);
}