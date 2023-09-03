#include "monty.h"

void
push(stack_t **st, unsigned int line)
{
	int i = 0, n;

	if (dat.arg != NULL)
	{
		if (dat.arg[0] == '-')
			i++;
		for (; dat.arg[i] != '\0'; i++)
		{
			if ((dat.arg[i] > 57 || dat.arg[i] < 48) && dat.arg[i] != 36)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
		}
		n = atoi(dat.arg);
		add_node(st, n);	
	}
}
