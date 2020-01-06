#include "monty.h"
/**
 * free_space - Entry
 * Desc: free_space function
 * @release: pointer to pointer stack_t
 * Return: Free space in momeries allocation
 **/
void free_space(stack_t **release)
{
	stack_t *getit = *release;

	while (*release != NULL)
	{
		getit = (*release)->next;
		free(*release);
		*release = getit;
	}
	free(kc.buffer);
	fclose(kc.fd);
}
