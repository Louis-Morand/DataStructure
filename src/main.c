/**
 * @file main.c
 * @author Aurelio LOURENCO, modification Louis MORAND, Benoit ARQUILLIERE
 * @brief Tp de test d'implémentation de différent types de listes
 *
 * @version 0.1
 * @date 2021-10-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Console.h>
#include "./stack/stack.h"
#include "./queue/queue.h"
#include "array_list/array_list.h"

float test(int a)
{
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
}

void test_array_list(Array_list *liste)
{
    init_array_list(liste);
    insert_at(liste, 2, 56);
    assert(liste->data[1] == 56);
    add(liste, 99);
    assert(liste->data[2] == 99);
    remove_at(liste, 2);
    assert(liste->data[1] == 99);
    assert((get_at(liste, 2)) == 99);
    clear_array(liste);
    assert(liste->index == 0);
}
void test_queue(Queue *queue)
{
    init_queue(queue);
    assert(is_queue_empty(queue) == true);
    enqueue(queue, 5);
    assert((queue->data[queue->index - 1]) == 5);
    assert((front(queue)) == 5);
    enqueue(queue, 6);
    assert(queue->data[queue->index - 1] == 6);
    enqueue(queue, 990);
    assert(queue->data[queue->index - 1] == 990);
    assert((dequeue(queue)) == 5);
    assert(front(queue) == 6);
    assert(is_queue_empty(queue) == false);
    clear_queue(queue);
    assert(is_queue_empty(queue) == true);
}

void test_stack(Stack *stack)
{

    init_stack(stack);
    assert(is_stack_empty(stack) == true);
    push_stack(stack, 18);
    assert(stack->data[stack->index]);
    push_stack(stack, 4);
    assert(stack->data[stack->index] == 4);
    push_stack(stack, 63);
    assert(stack->data[stack->index] == 63);
    peek_stack(stack);
    assert(stack->data[stack->index] == 63);
    pop_stack(stack);
    
    swap(stack);
    dup(stack);
}

int main(int argc, char **argv)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    Array_list *array = (Array_list *)(malloc(sizeof(Array_list)));

    test_array_list(array);
    test_queue(queue);
    test_stack(stack);

    return (EXIT_SUCCESS);
}
