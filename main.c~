#include "monty.h"

/**
 * main - Monty bite code files interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 *
 * Return: Void
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fd;
	char *file_n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_n = argv[1];
	fd = fopen(file_n, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_n);
		exit(EXIT_FAILURE);
	}

        handle_com(fd, &stack);
	free_stack(stack);
	fclose(fd);

	exit(EXIT_SUCCESS);
}
