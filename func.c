#include "func.h"

/**
 * facto - factorize a number
 * @num: the number
 * Return: nothing
 */

void facto(long int num)
{
	long int i;

	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%ld=%ld*%ld\n",num,num/i,i);
			break;
		}
	}
}

/**
 * gcd - Stein's Algorithm
 * @a: the first number
 * @b: the second number
 */

int gcd(int a, int b)
{
    if (a == b)
        return a;
 
    /* GCD(0, b) == b; GCD(a, 0) == a,
    // GCD(0, 0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    /* look for factors of 2 */
    if (~a & 1) /* a is even */
    {
        if (b & 1) /* b is odd */
            return gcd(a >> 1, b);
        else /* both a and b are even */
            return gcd(a >> 1, b >> 1) << 1;
    }
 
    if (~b & 1) /* a is odd, b is even */
        return gcd(a, b >> 1);
 
    /* reduce larger number */
    if (a > b)
        return gcd((a - b) >> 1, b);
 
    return gcd((b - a) >> 1, a);
}
