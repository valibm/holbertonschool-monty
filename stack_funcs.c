#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @opcode: Pointer to a string.
 * @top: Pointer to the top of a stack.
 * @line: Line number.
 *
 * Return: Void.
 */
void push(char *opcode, stack_t **top, unsigned int line)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	if (isnum(opcode) == 1 && opcode != NULL)
	{
		stack->n = atoi(opcode);
		stack->next = *top;
		stack->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (*top != NULL)
		(*top)->prev = stack;
	*top = stack;
}


/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of a stack.
 * @line: Number of the line.
 *
 * Return: Void.
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	stack_t *node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	node = tmp->next;
	tmp->next = node->next;
	node->next = *stack;
	tmp->prev = node;
	node->prev = NULL;
	*stack = node;
}

/**
 * pall - Prints all the values on the stack,
 *        starting from the top of the stack.
 * @stack: Pointer to the top of a stack.
 * @line: Unused.
 * Return: Void.
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line)
{
	int i = 0;
	stack_t *tmp;

	tmp = *stack;

	while (tmp)
	{
		if (tmp != NULL)
		printf("%d\n", tmp->n);
		i++;
		tmp = tmp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to the top of a stack.
 * @line: Number of the line.
 * Return: Void.
 */
void pint(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	tmp = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}
