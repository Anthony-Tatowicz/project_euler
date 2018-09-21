/*
 * @Author: anthony.tatowicz 
 * @Date: 2018-09-09 22:31:48 
 * @Last Modified by: anthony.tatowicz
 * @Last Modified time: 2018-09-10 00:56:51
 */

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "errors.h"

#define LIMIT 4000000u

/**
 * @brief solution to problem_2, sum the even Fibonacci numbers
 * less than 4 million
 * 
 * 1, 1, 2, 3, 5, 8, 13, 21, 34
 *       ^        ^           ^
 * 
 * We can easily prove that every third number is even
 * 
 * @return int 
 */
int main()
{
    // Set up our sequence
    uint32_t sum = 0;
    uint32_t fib[3] = {1u, 1u, 2u};

    while (fib[2] < LIMIT)
    {
        sum += fib[2];

        // Calculate every third number
        fib[0] = fib[1] + fib[2];
        fib[1] = fib[0] + fib[2];
        fib[2] = fib[0] + fib[1];
    }

    printf("%u\n", sum);

    return result_ok;
}