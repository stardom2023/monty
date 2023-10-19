#include "monty.h"

/**
 * _node - this sums node to the stack
 * @stack: head of the stack
 * @value: new value
 * Return: none
 */

void _node(stack_t **stack, int value)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (temp)
		temp->prev = new_node;
	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
