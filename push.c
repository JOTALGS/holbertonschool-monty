#include "monty.h"

void
push(stack_t **st, unsigned int line)
{
	int i = 0, n;

	if (dat.arg)
	{
		if (dat.arg[0] == '-')
			i++;
		for (; dat.arg[i] != '\0'; i++)
		{
			printf("dat.arg: %d\n", dat.arg[i]);
			if (dat.arg[i] > 57 || dat.arg[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
		}
		printf("{push.c}--->m.1\n");
		n = atoi(dat.arg);
		add_node(st, n);	
	}
}
