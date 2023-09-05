#include "monty.h"

void
pint_st(stack_t **st, unsigned int line)
{
	stack_t *aux;

	if (*st == NULL)
	{
		free_stack(st);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	aux = *st;
	while (aux->next != NULL)
		aux = aux->next;
	printf("%d\n", aux->n);
}
