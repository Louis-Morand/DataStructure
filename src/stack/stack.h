/**
 * @file stack.h
 * @author Aurelio LOURENCO
 * @brief 
 * @version 0.1
 * @date 2021-10-13
 * 
 * 
 */

#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef struct {
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

#endif /* STACK_H */

void init_stack(Stack *s);
void push_stack(Stack *s, float value);
float pop_stack(Stack *s);
bool is_stack_empty(Stack *s);
float peek(Stack *s);
void dup(Stack *s);
void swap(Stack *s);
void clear(Stack *s);

