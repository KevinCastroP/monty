#include "monty.h"
/**
 * op_push - function to push an element to the stack
 * @stack: contain the list
 * @line_number: numbers
 * Return: element number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value = kc.know;
	int k;

	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}
	else if (validate(value))
	{
		k = atoi(value);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_space(stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		free_space(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = k;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
