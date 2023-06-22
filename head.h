#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024

extern int stack[STACK_SIZE];
extern int top;

void push(int line_number, const char *argument);
void pint(int line_number);
void pall();
void pop(int line_number);
#endif
