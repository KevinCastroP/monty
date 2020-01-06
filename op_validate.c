#include "monty.h"
/**
 * validate - Entry point
 * Desc: validate function
 * @st: pointer to num
 * Return: Function that validates if it's number or not
 **/
int validate(char *st)
{
	int i;

	i = 0;

	while (st[i] != '\0')
	{
		if ((st[i] >= '0' && st[i] <= '9') || (st[i] == '-' && i == 0))
			i++;
		else
			return (0);
	}
	return (1);
}
