#include "monty.h"
dat_t dat = {NULL};

int
main(int arc, char **arv)
{
	FILE *file;
	char *line_cont;
	char *str;
	size_t ln = 0;
	char *token;
	char *line_cpy;
	const char *delim = " \n\t";
	ssize_t read_line = 1;
	unsigned int line = 0;
	void (*ptr)(stack_t **, unsigned int);
	stack_t *init_stack;

	init_stack = NULL;
	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(arv[1], "r");
	if (file)
	{
	while (read_line > 0)
	{
		line_cont = NULL;
		read_line = getline(&line_cont, &ln, file);
		line++;
		if (read_line != 0)
		{
			line_cpy = strdup(line_cont);
			token = strtok(line_cpy, delim);
			while (token)
			{
				ptr = execute(token);
				if (!ptr)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
					exit(EXIT_FAILURE);
				}
				else
				{
					token = strtok(NULL, delim);
					if (token)
					{
						str = strdup(token);
						dat.arg = str;
					}
					else
						dat.arg = NULL;
					ptr(&init_stack, line);
					if (token)
						free(str);
					break;
				}
			}
			free(line_cont);
			free(line_cpy);
		}
	}
	fclose(file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}
	free_stack(init_stack);
}
