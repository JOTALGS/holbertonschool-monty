#ifndef monty_H
#define monty_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *
 */
typedef struct dat_s
{
	char *arg;
} dat_t;
extern dat_t dat;

void (*execute(char *tk))(stack_t **, unsigned int);
void push(stack_t **st, unsigned int n); 
stack_t *add_node(stack_t **st, const int n);
void pall_st(stack_t **st, unsigned int line);
#endif
