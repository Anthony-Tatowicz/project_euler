/*
 * @Author: anthony.tatowicz 
 * @Date: 2018-09-03 23:27:06 
 * @Last Modified by: anthony.tatowicz
 * @Last Modified time: 2018-09-20 22:32:11
 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "errors.h"

/**
 * @brief Calculates the sum of 1..n in O(1) with ability to specifiy multiples
 * 
 * @param n number to sum to
 * @param d multiples to sum
 * @return uint64_t 
 */
long double sumn(int n, int d)
{
    long double m = floorl(n / d);

    return d * (m * (m + 1.0) / 2.0);
}

int main(void)
{
    uint32_t t;
    scanf("%u", &t);

    // Constrain entries to 1 million
    if (t > 1000000u)
        return 1;

    for (uint32_t a0 = 0; a0 < t; a0++)
    {
        int n;
        long double sum;
        int buff[3] = {5, 3, 15};

        scanf("%d", &n);

        // Constrain to 1 billion
        if (n > 1000000000u)
            return 1;

        // Sum up multiples ofre 3 and 5 subtract off common multiple of 15
        sum = sumn(n - 1, buff[0]) + sumn(n - 1, buff[1]) - sumn(n - 1, buff[2]);

        printf("%.0Lf\n", sum);
    }

    return 0;
}
