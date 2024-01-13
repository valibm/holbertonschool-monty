#include "monty.h"

/**
 * handle_com - Gets command from monty file.
 * @file: File to read to gets the command.
 * @stack: Linear data structure.
 *
 * Return: Void.
 */
void handle_com(FILE *file, stack_t **stack)
{
	char *opcode, *token = NULL;
	size_t size = 0;
	int counter = 0;

	while (getline(&opcode, &size, file) != -1)
	{
		counter++;
		token = strtok(opcode, "\n\t\r ");
		if (token == NULL || *token == '#')
			continue;

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			push(token, stack, counter);
		}
		else
			check_ops(token, stack, counter);
	}

	free(opcode);
}
