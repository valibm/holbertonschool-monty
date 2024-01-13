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

/**
 * check_ops - Checks the opcode in the line
 * @opcode: Requested function
 * @stack: Pointer to the top of the stack
 * @line: Line number
 *
 * Return: Function pointer or EXIT_FAILURE if it fails
 */
void check_ops(char *opcode, stack_t **stack, unsigned int line)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint",  pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line);
			break;
		}
		i++;
	}

	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}
