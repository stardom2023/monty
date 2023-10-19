#include "monty.h"

/**
 * print_str - this prints the string
 * @stack: head of stack
 * @line: line count
 * Return: none
 */

void print_str(stack_t **stack, unsigned int line)
{
	stack_t *h;
	(void)line;

	h = *stack;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
