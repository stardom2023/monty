#include "monty.h"

/**
 * remove_top - this prints the top of the stack
 * @stack: pointer to the stack
 * @line: line count
 * Return: none
 */

void remove_top(stack_t **stack, unsigned int line)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}

/**
* print_top - this prints the top of the stack
* @stack: double head pointer to the stack
* @line: line count
* Return: none
*/

void print_top(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* do_noth - function that does nothing
* @stack: double head pointer to the stack
* @line: line count
* Return: none
*/

void do_noth(stack_t **stack, unsigned int line)
{
	(void) line;
	(void) stack;
}
