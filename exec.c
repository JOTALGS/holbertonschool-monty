#include "monty.h"

int
(*execute(char *args))(stack_t **, unsigned int)
{
	int f, i, c;

	instruction_t mont[] = {
				{"push", push},
				{"pall", pall},
				{NULL, NULL}
			};
	i = 0;
	while (args[i])
	{
		c = 0;
		while (c < 2)
		{
			if (strcmp(args[i], mont[c].opcode) == 0)
			{
				return (mont[c].f);
			}
			c++;
		}
		i++;
	}
	return (NULL);
}
