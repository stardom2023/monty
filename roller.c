#include "monty.h"

/**
* rot_left- this rotates the stack to the top
* @stack: head of the stack
* @line: line count
* Return: none
*/

void rot_left(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}

/**
* rot_right - this rotates the stack to the bottom
* @stack: stack head of the stack
* @line: line count
* Return: none
*/

void rot_right(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
