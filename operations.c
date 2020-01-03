#include "monty.h"
/**
 * get_op_func - get the function
 * @token: contain the operator
 * Return: integer flag operator
 */

void (*get_op_func(char *token))(stack_t**, unsigned int)
{

	instruction_t operations[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop}
	};

	int i = 0;

	while (operations[i].opcode != NULL)
	{
		if (!strcmp(operations[i].opcode, token))
			return (operations[i].f);
		i++;
	}
	return (NULL);
}
