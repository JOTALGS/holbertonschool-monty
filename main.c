#include "monty.h"
dat_t dat = {NULL};

int
main(int arc, char **arv)
{
	FILE *file;
	char *line_cont;
	size_t ln = 0;
	char *token;
	char *line_cpy;
	const char *delim = " \n";
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
	while (read_line > 0)
	{
		line_cont = NULL;
		read_line = getline(&line_cont, &ln, file);
		line++;
		line_cpy = strdup(line_cont);
		token = strtok(line_cpy, delim);
		while (token)
		{
			ptr = execute(token);
			if (!ptr)
				token = strtok(NULL, delim);
			else
			{
				token = strtok(NULL, delim);
				dat.arg = strdup(token);
				ptr(&init_stack, line);
			}
		}
	}
}
