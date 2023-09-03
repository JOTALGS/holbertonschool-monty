#include "monty.h"

void
pall_st (stack_t **st, unsigned int line)
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
		while(ptr->prev)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->prev;
		}
		printf("%d\n", ptr->n);
	}
}
