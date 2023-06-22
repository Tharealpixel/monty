#include "head.h"
int stack[STACK_SIZE];
int top = -1;
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return EXIT_FAILURE;
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Cannot open file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	while (fgets(line, sizeof(line), file))
	{
		char *opcode;
		char *argument;

		opcode = strtok(line, " \t\n");
		argument = strtok(NULL, " \t\n");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
				push(line_number, argument);
			else if (strcmp(opcode, "pall") == 0)
				pall();
			else if (strcmp(opcode, "pint") == 0)
				pint(line_number);
			else if (strcmp(opcode, "pop") == 0)
				pop(line_number);
			else
			{
				fprintf(stderr, "L%d: unknown opcode: %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}

		line_number++;
	}

	fclose(file);
	return EXIT_SUCCESS;
}
