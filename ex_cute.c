#include "monty.h"
/**
 * ex_inst - this executes the opcode
 * @inst: line count
 * @stack: head stack linked list
 * @line: line count
 * @file: pointer to the file stream
 * Return: none
 */
int ex_inst(char *inst, stack_t **stack, unsigned int line, FILE *file)
{
		instruction_t opst[] = 
		{
		{"push", insert}, {"pall", display}, {"pint", print_top},
		{"pop", remove_top}, {"swap", switch_top}, {"add", sum},
		{"nop", do_noth}, {"sub", sub_top}, {"div", div_top},
		{"mul", mul_top}, {"mod", calc_mod}, {"pchar", print_char},
		{"pstr", print_str}, {"rotl", rot_left}, {"rotr", rot_right},
		{"queue", use_queue}, {"stack", use_stack}, {NULL, NULL},
		};
	unsigned int c = 0;
	char *op;

	op = strtok(inst, " \n\t");

	if (op && op[0] == '#')
	return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[c].opcode && op)
	{
		if (strcmp(op, opst[c].opcode) == 0)
		{
			opst[c].f(stack, line);
			return (0);
		}
		c++;
	}
	if (op && opst[c].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		fclose(file);
		free(inst);
		clear_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
