#include "monty.h"
/**
 * op_pall - function to print all elements of a double linkedlist
 * @stack: pointer to a value
 * @line_number: a value
 * Return: the number of nodes
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *gotit = *stack;

	while (gotit != NULL)
	{
		printf("%d\n", (gotit)->n);
		gotit = (gotit)->next;
	}
	(void)line_number;
}
