/*
 * @Author: anthony.tatowicz 
 * @Date: 2018-10-03 22:49:45 
 * @Last Modified by:   anthony.tatowicz 
 * @Last Modified time: 2018-10-03 22:49:45 
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Reverse the number pretty simple method
 * 
 * @param n 
 * @return uint32_t 
 */
uint32_t reverse(uint32_t n)
{
    uint32_t reversed = 0;

    while (n != 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return reversed;
}

/**
 * @brief Is it a palindrome? well is the reverse 
 *        equal to the original
 * 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPalindrome(uint32_t n)
{
    return n == reverse(n);
}

int main()
{
    uint32_t lgst_palindrome = 0;

    for (uint16_t i = 100; i < 999; i++)
    {
        for (uint16_t j = 100; j < 999; j++)
        {
            if (isPalindrome(i * j) && lgst_palindrome < (i * j))
            {
                lgst_palindrome = i * j;
            }
        }
    }

    printf("%d", lgst_palindrome);

    return 0;
}