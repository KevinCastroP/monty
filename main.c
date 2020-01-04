#include "monty.h"
int number = 0;
/**
 * main - function of Monty project
 * @argc: counter argument
 * @argv: vector argument
 * Return: a value
 */
int main(int argc, char *argv[])
{
	char *buffer, *token = NULL, *num;
	stack_t *header = NULL;
	FILE *file_name;
	size_t buffsize = 1024;
	ssize_t line_size;
	unsigned int countline = 0;
	void (*f)(stack_t **, unsigned int);

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		file_name = fopen(argv[1], "r");
		if (file_name == NULL)
		{
			fprintf(stderr, "Error, Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		buffer = (char *)malloc(buffsize * sizeof(char));
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		line_size = getline(&buffer, &buffsize, file_name);
		while (line_size >= 0)
		{
			countline++;
			token = strtok(buffer, "\n\t\r ");
			if (token != NULL)
			{
				printf("%s\n", token);
			}
			num = strtok(NULL, "\n\t\r ");
			if (num != NULL)
				printf("%s\n", num);
			f = operations(token);
			if (f != NULL)
				f(&header, countline);
			line_size = getline(&buffer, &buffsize, file_name);
		}
		free_dlistint(header);
		free(buffer);
		buffer = NULL;
		fclose(file_name);
	}
	return (0);
}
