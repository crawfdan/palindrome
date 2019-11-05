#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    __uint32_t i = 1;
    
    for(i = 1; i < 100; i++)
    {
        if (isPalindrome(i))
        {
            printf("%u is a palindrome.\n", i);
        }

        else
        {
            printf("%u is not a palindrome.\n", i);
        }
        
    }
    return 0;
}

bool isPalindrome(__uint32_t num)
{
    bool result = false;
    __uint32_t numReversal = 0;
    __uint32_t temp = num;

    //find how many digits in num
    int numSize = 10;
    int numSizeResult = -1;

    do
    {
        //divide num by power of 10 until not possible (number of digits in num)
        numSizeResult = num / numSize;
        numSize *= 10;
    } while (numSizeResult != 0);

    //numSize should be 1 power too  big at this point
    numSize /= 10;

    int revResult = 0;
    //reverse num and store to compare with num by reconstructing
    while (numSize != 0)
    {
        revResult = temp % 10;
        numReversal += (revResult * numSize);
        numSize /= 10;
    }

    if (numReversal == num)
    {
        result = true;
    }

    return result;
}