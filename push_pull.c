#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @line_number: The line number of the instruction in the Monty bytecode file
 * @argument: The argument of the push instruction (integer to push)
 * Description: This function pushes an element on the stack
 * by doing alot checking
 */
void push(int line_number, const char *argument)
{
	int stack[STACK_SIZE];
	int top = -1;
	int num;

	if (argument == NULL || sscanf(argument, "%d", &num) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top >= STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack[++top] = num;
}
/**
 * pall - Prints all the values on the stack
 *
 * Description: This function prints all the values on the stack
 */
void pall(void)
{
	int stack[STACK_SIZE];
	int i, top = -1;

	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
