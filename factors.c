#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void facto(long int num);

int main(int argc, char *argv[])
{
	FILE *file;
	size_t count;
	ssize_t nb;
	char *buffer = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while((nb = getline(&buffer, &count, file)) != -1)
	{
		facto(atol(buffer));
	}

	return (0);
}


/**
 * facto - factorize a number
 * @num: the number
 * Return: nothing
 */

void facto(long int num)
{
	long int i;

	for (i = 2; i < (num / 2) + 1; i++)
	{
		if (num % i == 0)
		{
			printf("%ld=%ld*%ld\n",num,num/i,i);
			break;
		}
	}
}
