#include "monty.h"

void
pop(stack_t **st, unsigned int line)
{
	stack_t *temp;
	stack_t *ptr;

	temp = malloc(sizeof(stack_t));
	if (!temp)
		exit(EXIT_FAILURE);
	if (!*st)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_stack(&*st);
		exit(EXIT_FAILURE);
	}
	ptr = *st;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr->prev)
	{
		temp = ptr->prev;
		temp->next = NULL;
		*st = temp;
	}
	else
	{
		*st = NULL;
	}
	free(temp);
}
