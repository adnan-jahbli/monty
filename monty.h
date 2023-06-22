#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

#define DELIM " \t\r\n\v\a"

/* global variables */
extern char *argv_p, *line, **instructions;
extern int line_count;
extern FILE *file;
extern stack_t *stack;

/* functions prototypes */
void error_msg(int error_type);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **split_line(char *str);
void (*check_instruction(char **))(stack_t **, unsigned int);
void _push(stack_t **stack, unsigned int line_number);
char *_strdup(const char *str);
void _pall(stack_t **stack, unsigned int line_number);
void free_double_pointer(char **ptr);
void free_linked_list(stack_t *head);

#endif