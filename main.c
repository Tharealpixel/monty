#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

int stack[STACK_SIZE];
int top = -1;

void push(line_number, argument)
    int line_number;
    const char *argument;
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

void pall()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main(argc, argv)
    int argc;
    char *argv[];
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
