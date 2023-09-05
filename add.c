#include "monty.h"

void
add(stack_t **st, unsigned int line)
{
	stack_t *ptr = *st;
	int sum = 0, len = 1;

	if (!*st)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(st);
		exit(EXIT_FAILURE);
	}
	while (ptr->prev)
		ptr = ptr->prev;
	while (ptr->next)
	{
		ptr = ptr->next;
		len++;
	}
	if (len > 1)
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
