#include "monty.h"

void
(*execute(char *tk))(stack_t **, unsigned int)
{
	int c;

	instruction_t mont[] = {
				{"push", push},
				{NULL, NULL}
			};

	c = 0;
	while (c < 1)
	{
		if (strcmp(tk, mont[c].opcode) == 0)
		{
			return (mont[c].f);
		}
		c++;
	}
	return (NULL);
}
