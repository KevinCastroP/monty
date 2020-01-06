#include "monty.h"
/**
 * op_pop - function to remove the top element
 * @stack: pointer to list
 * @line_number: # of line
 * Return: nothing
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *gotit = *stack;

	if (gotit != NULL)
	{
		gotit = (*stack)->next;
		if (gotit != NULL)
			gotit->prev = NULL;
		free(*stack);
		*stack = gotit;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}
