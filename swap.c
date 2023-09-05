#include "monty.h"

void
swap(stack_t **st, unsigned int line)
{
	stack_t *t, *temp;
	int aux;

	if (*st)
	{
		t = *st;
		while (t->next)
			t = t->next;
		if (t->prev)
		{
			temp = t->prev;
			aux = t->n;
			t->n = temp->n;
			temp->n = aux;
			return;
		}
	}
	fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	free_stack(&*st);
	exit(EXIT_FAILURE);
}
