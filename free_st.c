#include "monty.h"

void
free_stack(stack_t **st)
{
	stack_t *ptr = *st;

	while (ptr)
	{
		free(ptr);
		ptr = ptr->next;
	}
}
