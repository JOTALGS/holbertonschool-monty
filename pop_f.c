#include "monty.h"

void
pop(stack_t **st, unsigned int line)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
		exit(EXIT_FAILURE);
	if (!*st)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free(temp);
		free_stack(*st);
		exit(EXIT_FAILURE);
	}
	temp = *st;
	while (temp->next)
		temp = temp->next;
	if (temp->prev)
	{
		temp = temp->prev;
		temp->next = NULL;
		*st = temp;
	}
	else
	{
		*st = NULL;
	}
}
