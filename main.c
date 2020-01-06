#include "monty.h"
/**
 * main - function of Monty project
 * @argc: counter argument
 * @argv: vector argument
 * Return: a value
 */
int main(int argc, char *argv[])
{
	if (argc > 2 || argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		receive(argv[1]);
	}
	return (0);
}
/**
 * receive - entry point to function
 * @file_name: pointer to a value
 * Return: a value
 */
int receive(char *file_name)
{
	char *inst;
	size_t bufsize = 1024;
	stack_t *stack = NULL;
	unsigned int cline = 0;
	void (*f)(stack_t **, unsigned int);

	kc.fd = fopen(file_name, "r");
	if (kc.fd == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	else
	{	kc.buffer =  malloc(1024);
		if (kc.buffer == NULL)
		{	fprintf(stderr, "Error: malloc failed\n");
			free(kc.buffer);
			exit(EXIT_FAILURE);
		}
		while (getline(&(kc.buffer), &bufsize, kc.fd) != -1)
		{	cline++;
			inst = strtok(kc.buffer, "\n\t\r ");
			kc.know = strtok(NULL, "\n\t\r ");
			if (inst != NULL && inst[0] != '#')
			{	f = get_op_func(inst);
				if (f != NULL)
					f(&stack, cline);
				else
				{	fprintf(stderr, "L%u: unknown instruction %s\n", cline, inst);
					free(kc.buffer);
					free_space(&stack);
					exit(EXIT_FAILURE);
				}
			}

		}
	}
	free(kc.buffer);
	kc.buffer = NULL;
	fclose(kc.fd);
	return (0);
}
