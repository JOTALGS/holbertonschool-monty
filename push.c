#include "monty.h"

int
push(stack_t **st, unsigned int n)
{
	stack_t *tmp;
	stack_t *ptr = *st;

	if (!ptr)
	{
		tmp = malloc(sizeof(stack_t));
		tmp->n = n;
		tmp->prev = NULL;
		tmp->next = NULL;
		ptr = tmp;
	}
	else if (ptr->next)
	{
		while (ptr->next)
			ptr = ptr->next;
		tmp = malloc(sizeof(stack_t));
		tmp->n = n;
		tmp->prev = ptr;
		tmp->next = NULL;
		ptr->next = tmp;
	}
	else
	{
		tmp = malloc(sizeof(stack_t));
		tmp->n = n;
		tmp->prev = ptr;
		tmp->next = NULL;
		ptr->next = tmp;
	}
}
