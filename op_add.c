#include "monty.h"
/**
 * op_add - function to add the top two elements of the stack.
 * @stack: pointer to list
 * @line_number: # of line
 * Return: nothing
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	op_pop(stack, line_number);
}
