#include "monty.h"

int
main(int arc, char **arv)
{
	char *opcode;
	int i = 0;
	unsigned int a;
	int line = 0;
	void (*ptr)(stack_t **, unsigned int);
	stack_t *init_stack;

	init_stack = NULL;
	while (arv[i])
		{
			if (arv[i] == '\n')
				line++;
		}
	ptr = execute (arv);
	if (ptr)
	{
		a = atoi(arv[i + 1]);
		ptr(init_stack, a);
	}
	i++;
}
