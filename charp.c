#include "monty.h"

/**
* print_char - this prints the char at the top of the stack,
* @stack: stack head
* @line: line count
* Return: nothing
*/

void print_char(stack_t **stack, unsigned int line)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
* use_queue - function that prints the top of the queue
* @stack: head of queue
* @line: line count
* Return: none
*/
void use_queue(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	bus.lifi = 1;
}

/**
* enqueue - this adds node to the tail the queue
* @value: new value
* @stack: head of the queue
* Return: none
*/
void enqueue(stack_t **stack, int value)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = value;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
