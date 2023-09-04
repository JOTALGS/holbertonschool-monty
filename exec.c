#include "monty.h"

void
(*execute(char *tk))(stack_t **, unsigned int)
{
	int c;

	instruction_t mont[] = {
				{"push", push},
				{"pall", pall_st},
				{"pint", pint_st},
				{NULL, NULL}
			};

	c = 0;
	while (c < 2)
	{
		if (strcmp(tk, mont[c].opcode) == 0)
		{
			return (mont[c].f);
		}
		c++;
	}
	return (NULL);
}
