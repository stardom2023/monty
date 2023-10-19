#include "monty.h"

/**
* display - this prints everything in the stack
* @stack: double head pointer to the stack
* @line: line count
* Return: none
*/

void display(stack_t **stack, unsigned int line)
{
	stack_t *h;
	(void)line;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->value);
		h = h->next;
	}
}

/**
* switch_top - this swaps the top two elements of the stack
* @stack: head of stack
* @line: line count
* Return: none
*/

void switch_top(stack_t **stack, unsigned int line)
{
	stack_t *h;
	int len = 0, temp;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
