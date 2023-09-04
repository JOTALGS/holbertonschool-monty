#include "monty.h"

void
pint_st(stack_t **st, unsigned int line)
{
	stack_t *ptr;
	(void)line;

	ptr = *st;
	if (ptr)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		printf("%d\n", ptr->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
}
