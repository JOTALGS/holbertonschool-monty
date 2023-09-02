#include "monty.h"

stack_t
*add_node(stack_t **st, const int n)
{
	stack_t *temp;
	stack_t *ptr = *st;
	
	temp = malloc(sizeof(stack_t));
	if (!temp)
		return (0);
	temp->n = n;
	temp->next = NULL;
	if (ptr)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
	}
	else
	{
		temp->prev = NULL;
		*st = temp;
	}
	return (temp);	
}
