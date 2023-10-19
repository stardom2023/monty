#include "monty.h"

/**
* sum - sum the elements of stack
* @stack: double pointer head to the stack
* @line: line count
* Return: none
*/

void sum(stack_t **stack, unsigned int line)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}

/**
* sub_top - function that substracts nodes
* @stack: double head pointer to the stack
* @line: line count
* Return: None
*/
void sub_top(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	int minus, nd;

	temp = *stack;
	for (nd = 0; temp != NULL; nd++)
		temp = temp->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	minus = temp->next->n - temp->n;
	temp->next->n = minus;
	*stack = temp->next;
	free(temp);
}
/**
* mul_top - this multiplies the top two elements of the stack
* @stack: double head pointer to the stack
* @line: line count
* Return: none
*/
void mul_top(stack_t **stack, unsigned int line)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
/**
* div_top - this divides the top two elements of the stack
* @stack: double head pointer to the stack
* @line: line count
* Return: None
*/
void div_top(stack_t **stack, unsigned int line)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
/**
* calc_mod - this  computes the remainder of the division of an element
* @stack: double head pointer to the stack
* @line: line count
* Return: none
*/

void calc_mod(stack_t **stack, unsigned int line)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
