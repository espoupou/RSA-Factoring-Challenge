#include "func.h"

/**
 * facto - factorize a number
 * @num: the number
 * Return: nothing
 */

void facto(long int num)
{
	long int i;

	if (num == 0)
	{
		printf("0=0*0\n");
		return;
	}
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%ld=%ld*%ld\n",num,num/i,i);
			return;
		}
	}
	printf("%ld=%ld*%ld\n",num,num,(long int)1);
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

/**
 * g - pseudorandom function
 * @x: the parameter
 * @n: second parameter
 * return: long int
 */

long int g(long int x, long int n)
{
	return ((x * x + 1) % n);
}

/**
 * abso -  absolut value
 * @x: first param
 * Return: long int
 */

long int abso(long int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/**
 * facto2 - second method
 * @num: the number
 * Return: nothing
 */

void facto2(long int num)
{
	long int x = 2, y = 2, d = 1;

	while (d == 1)
	{
		x = g(x, num);
		y = g(g(y, num), num);
		d = gcd(abso(x - y), num);
	}

	if (d == num)
		facto(num);
	else if (d < num / d)
		printf("%ld=%ld*%ld\n",num,num/d, d);
	else
		printf("%ld=%ld*%ld\n",num,d, num/d);
}
