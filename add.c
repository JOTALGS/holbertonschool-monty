#include "monty.h"

void
add(stack_t **st, unsigned int line)
{
	stack_t *ptr = *st;
	int sum = 0, len = 0;

	while (ptr->next)
	{
		ptr = ptr->next;
		len++;
	}
	len++;
	if (len > 2)
	{
		sum += ptr->n;
		ptr = ptr->prev;
		sum += ptr->n;
		ptr->n = sum;
		ptr->next = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(st);
		exit(EXIT_FAILURE);
	}
}
