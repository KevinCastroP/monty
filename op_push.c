#include "monty.h"
/**
 * op_push - function to pushes an element to the stack
 * @header: contain the list
 * @line_number: numbers
 * Return: element number
 */
void op_push(stack_t **header, unsigned int line_number)
{
	stack_t *new_head = malloc(sizeof(stack_t));

	if (new_head == NULL)
	{
		free(new_head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_head->n = number;
	new_head->next = *header;
	new_head->prev = NULL;
	if (*header != NULL)
	{
		(*header)->prev = new_head;
	}
	*header = new_head;
}
