#ifndef TADEM_H
#define TADEM_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
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

/**
* struct bus_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
*
* Description: carries values through the program
*/
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

void insert(stack_t **stack, unsigned int line);
void display(stack_t **stack, unsigned int line);
void print_top(stack_t **stack, unsigned int line);
int ex_inst(char *inst, stack_t **stack, unsigned int line, FILE *file);
void clear_stack(stack_t *stack);
void remove_top(stack_t **stack, unsigned int line);
void switch_top(stack_t **stack, unsigned int line);
void sum(stack_t **stack, unsigned int line);
void do_noth(stack_t **stack, unsigned int line);
void sub_top(stack_t **stack, unsigned int line);
void div_top(stack_t **stack, unsigned int line);
void mul_top(stack_t **stack, unsigned int line);
void calc_mod(stack_t **stack, unsigned int line);
void print_char(stack_t **stack, unsigned int line);
void print_str(stack_t **stack, unsigned int line);
void rot_left(stack_t **stack, __attribute__((unused)) unsigned int line);
void rot_right(stack_t **stack, __attribute__((unused)) unsigned int line);
void _node(stack_t **stack, int value);
void enqueue(stack_t **stack, int value);
void use_queue(stack_t **stack, unsigned int line);
void use_stack(stack_t **stack, unsigned int line);
int main(int argc, char *argv[]);

#endif
