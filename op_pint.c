#include "monty.h"
/**
 * op_pint - prints the value at the top of the stack,
 * @stack: address of the top of the stack.
 * @line_number: Number of the line below the cursor.
 * Return: nothing
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
