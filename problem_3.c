/*
 * @Author: anthony.tatowicz 
 * @Date: 2018-09-10 23:17:13 
 * @Last Modified by: anthony.tatowicz
 * @Last Modified time: 2018-09-20 23:06:08
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "errors.h"

#define LIMIT 600851475143L

/**
 * @brief This efficently calculates the prime factors of the n
 *        and then will print out the largest of those factors
 *
 * This works as follows
 * 1) Calculate all even factors (2 is prime)
 * 2) Now that all even factors are completed we can look at
 *    only odd factors, hence i = i + 2, also we only have to 
 *    calculate up to sqrt(n) because of the propery of primes
 *    that states that every composite number n has some prime 
 *    factor <= sqr(n)
 * 3) Go through every factor i from 3 ... sqrt(n) and remove that
 *    factor by divison
 * 
 * @param n 
 */
void lgst_prime_factor(int64_t n)
{
    while (n % 2 == 0)
        n = n / 2;

    for (int64_t i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
            n = n / i;
    }

    if (n > 2)
        printf("%d\n", n);
}

int main()
{
    lgst_prime_factor(LIMIT);
    return 0;
}
