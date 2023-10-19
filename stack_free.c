#include "monty.h"

/**
 * clear_stack - this frees a doubly linked list
 * @stack: head points to the stack
 * Return: none
 */

void clear_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * use_stack - this prints the top
 * @stack: the stack head
 * @line: count
 * Return: none
 */

void use_stack(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	bus.lifi = 0;
}
