#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty interpreter
 * @argc: argument count
 * @argv: argument value
 * Return: success 0
 */

int main(int argc, char *argv[])
{
	char *inst;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		inst = NULL;
		read_line = getline(&inst, &size, file);
		bus.content = inst;
		line++;
		if (read_line > 0)
		{
			ex_inst(inst, &stack, line, file);
		}
		free(inst);
	}
	clear_stack(stack);
	fclose(file);

	return (0);
}
