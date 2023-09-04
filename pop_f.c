#include "monty.h"

void
pop(stack_t **st, unsigned int line)
{
	stack_t *temp;
	
	if(!*st)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
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
		free(temp);
	}
	else
	{
		free(temp);
		*st = NULL;
	}
}
