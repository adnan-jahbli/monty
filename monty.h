#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_data - global structure to use in the functions
 * @lifo_mode: flag for stack or queue mode
 * @counter: current line number
 * @argument: second parameter inside the current line
 * @head: doubly linked list
 * @file_ptr: file pointer
 * @buffer: input text
 *
 * Description: global structure for stack, queues, LIFO, FIFO project
 */
typedef struct global_data
{
	int lifo_mode;
	unsigned int counter;
	char  *argument;
	stack_t *head;
	FILE *file_ptr;
	char *buffer;
} global_data;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **, unsigned int);
} instruction_t;

extern global_data global_vars;

/* opcode instructions */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void set_queue_mode(stack_t **, unsigned int);
void set_stack_mode(stack_t **, unsigned int);
void add_top_two_elements(stack_t **, unsigned int);
void do_nothing(stack_t **, unsigned int);
void subtract_top_element(stack_t **, unsigned int);
void divide_top_by_second(stack_t **, unsigned int);
void multiply_top_to_second(stack_t **, unsigned int);
void compute_modulo(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);

/* get function */
void (*get_opcode_func(char *))(stack_t **, unsigned int);

/* imported functions */
int sch(char *, char);
char *strtoky(char *, char *);
void *my_realloc(void *, unsigned int, unsigned int);
void *my_calloc(unsigned int, unsigned int);
int strcmpy(char *, char *);

/* doubly linked list functions */
stack_t *add_node_end(stack_t **, const int);
stack_t *add_node(stack_t **, const int);
void free_doubly_linked_list(stack_t *);

/* main */
void free_global_vars(void);

#endif
