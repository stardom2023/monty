#include "monty.h"

/**
 * insert - this adds nodes
 * @stack: points to the stack
 * @line: line count
 * Return: none
 */

void insert(stack_t **stack, unsigned int line)
{
	int c, m = 0, flag = 0;

	if (bus.arg)
	{

		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(bus.file);
			free(bus.content);
			clear_stack(*stack);
			exit(EXIT_FAILURE); }}

	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(bus.file);
		free(bus.content);
		clear_stack(*stack);
		exit(EXIT_FAILURE); }
	c = atoi(bus.arg);
	if (bus.lifi == 0)
		_node(stack, c);
	else
		enqueue(stack, c);
}
