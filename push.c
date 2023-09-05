#include "monty.h"

void
push(stack_t **st, unsigned int line)
{
	int i = 0, n;
	stack_t *new_node;
	stack_t *ptr = *st;

	if (dat.arg != NULL)
	{
		if (dat.arg[0] == '-')
			i++;
		for (; dat.arg[i] != '\0'; i++)
		{
			if ((dat.arg[i] > 57 || dat.arg[i] < 48) && dat.arg[i] != 36)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				free_stack(st);
				exit(EXIT_FAILURE);
			}
		}
		n = atoi(dat.arg);
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
			exit(EXIT_FAILURE);
		if (ptr)
		{
			while (ptr->next)
			{
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->prev = ptr;
		}
		else
		{
			*st = new_node;
		}
		new_node->n = n;
		new_node->next = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_stack(st);
		exit(EXIT_FAILURE);
	}
}
