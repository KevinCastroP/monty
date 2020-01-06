#include "monty.h"
/**
 * op_pint - prints the value at the top of the stack,
 * @stack: address of the top of the stack.
 * @line_number: Number of the line below the cursor.
 * Return: nothing
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *gotit = *stack;

	if (gotit != NULL)
	{
		printf("%d\n", (gotit)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
}
