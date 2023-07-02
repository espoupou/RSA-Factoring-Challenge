#include "func.h"

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
		facto2(atol(buffer));
	}

	return (0);
}
