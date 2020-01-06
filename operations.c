#include "monty.h"
/**
 * get_op_func - get the function
 * @inst: contain the operator
 * Return: integer flag operator
 */

void (*get_op_func(char *inst))(stack_t**, unsigned int)
{

	instruction_t operations[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	int i = 0;

	while (operations[i].opcode != NULL)
	{
		if (strcmp(inst, operations[i].opcode) == 0)
			return (operations[i].f);
		i++;
	}
	return (NULL);
}
