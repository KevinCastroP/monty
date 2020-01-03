#include "monty.h"
/**
 * free_dlistint - function to free a  lilstint_t list
 * @head: pointer to head element
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *inst;

	while (head != NULL)
	{
		inst = head->next;
		free(head);
		head = inst;
	}
}
