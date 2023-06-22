#include "head.h"

/**
 * push - Pushes an integer onto the stack
 * @line_number: Line number in the bytecode file
 * @argument: Argument to be pushed onto the stack
 */
void push(int line_number, const char *argument)
{
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
 * pint - Prints the value at the top of the stack
 * @line_number: Line number in the bytecode file
 */
void pint(int line_number)
{
	if (top == -1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack[top]);
}
/**
 * pall - Prints all the values in the stack
 */
void pall()
{
	int i;
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
void pop(int line_number) {
    if (top == -1) {
        fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    top--;
}
