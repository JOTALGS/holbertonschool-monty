#include "monty.h"


void freeList(stack_t *stack)
{
	if (stack != NULL)
	{
		if (stack->next != NULL)
			freeList(stack->next);
		free(stack);
	}
}
/**
 * pint_st - prits the value at the top of the stack
 * @st: the stack
 * @line: the line of the command
*/
void pint_st(stack_t **st, unsigned int line)
{
	stack_t *aux;

	if (*st == NULL)
	{
		freeList(*st);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	aux = *st;
	while (aux->next != NULL)
		aux = aux->next;
	printf("%d\n", aux->n);
}
