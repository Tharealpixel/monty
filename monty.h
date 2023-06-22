#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

extern int stack[STACK_SIZE];
extern int top;

void push(int line_number, const char *argument);
void pall();
void processInstruction(const char *instruction, int line_number);
char *_strdup(const char *str);
#endif
