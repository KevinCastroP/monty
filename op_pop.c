#include "monty.h"
/**
 * op_pop - function to remove the top element
 * @stack: pointer to list
 * @line_number: # of line
 * Return: nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = *stack;
	if ((*next).next != NULL)
	{
		(*(*next).next).prev = NULL;
	}
	*stack = (*next).next;
	free(next);
}
