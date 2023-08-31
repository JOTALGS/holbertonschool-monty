#include "monty.h"

stack_t
*add_node(stack_t **st, const int n)
{
	stack_t *temp;
	stack_t *ptr = *st;
	
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "malloc failed");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->next = NULL;
	printf("{add_node.c]--->1\n");
	if (!ptr)
	{
		temp->prev = NULL;	
		printf("{add_node.c}--->2\n");
		*st = temp;
	}
	return (temp);
}
