#include "monty.h"

/**
 * processInstruction - Process a Monty bytecode instruction
 * @instruction: The instruction string to process
 * @line_number: The line number of the instruction in the Monty bytecode file
 *
 * Description: This function parses and executes a Monty bytecode instruction.
 * It determines the opcode and the argument, and calls the corresponding
 * function for further processing.
 */
void processInstruction(const char *instruction, int line_number)
{
	char *instruction_copy;
	char *opcode;
	char *argument;

	instruction_copy = _strdup(instruction);
	if (instruction_copy == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(instruction_copy, " \t\n");
	argument = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		if (strcmp(opcode, "push") == 0)
			push(line_number, argument);
		else if (strcmp(opcode, "pall") == 0)
			pall();
		else
		{
			fprintf(stderr, "L%d: unknown opcode: %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(instruction_copy);
}
