#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of a stack.
 * @line: Number of a line.
 *
 * Return: Void.
 */
void add(stack_t **stack, unsigned int line)
{
	int addition;
	stack_t *tmp;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

        addition = tmp->n + tmp->next->n;
	pop(stack, line);

	(*stack)->n = addition;
}

/**
 * nop - Doesn’t do anything.
 * @stack: Pointer to the top of a line.
 * @line: Number of a line.
 *
 * Return: Void.
 */
void nop(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
}
