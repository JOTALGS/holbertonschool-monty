#include "monty.h"

void
pall_st (stack_t **st, unsigned int line)
{
	stack_t *ptr;
	(void)line;

	ptr = *st;
	if (!ptr)
		printf("Empty stack.");
	while (ptr->next)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->n);
}
