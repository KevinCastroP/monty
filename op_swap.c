#include "monty.h"
/**
 * op_swap - function to change the 1 and 2 elements
 * @stack: pointer to list
 * @line_number: # of line
 * Return: nothing
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int gotit_n;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		gotit_n = (*stack)->next->n;
		(*stack)->next->n = (*stack)->n;
		(*stack)->n = gotit_n;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}
