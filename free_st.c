#include "monty.h"

void
free_stack(stack_t *st)
{
	stack_t *temp;

	temp = st;
	while (st)
	{
		temp = st->next;
		free(st);
		st = temp;
	}
}
