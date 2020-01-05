#include "monty.h"
/**
 * op_pall - function to print all elements of a double linkedlist
 * @header: pointer to a value
 * @n: a value
 * Return: the number of nodes
 */
void op_pall(stack_t **header, unsigned int n)
{
	int k = 0;
	stack_t *count = *header;
	(void)(n);

	if (count == NULL)
	{
		return;
	}
	while (count != NULL)
	{
		printf("%d\n", count->n);
		count = count->next;
		k++;
	}
}
