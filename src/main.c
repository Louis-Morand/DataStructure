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
#include "./stack/stack.h"
#include "./queue/queue.h"

float test(int a) {
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

}



int main(int argc, char** argv) {
    // Queue *q = (Queue *)malloc(sizeof(Queue));
    // Stack *stack = (Stack *)malloc(sizeof(Stack));
    // float val;
    // bool is_empty;

    // init_queue(q);
    // is_empty = is_queue_empty(q);
    // enqueue(q, 5);
    // val = front(q);
    // enqueue(q, 6);
    // val = front(q);
    // enqueue(q, 990);
    // val = front(q);  
    // dequeue(q);
    // val = front(q);
    // is_empty = is_queue_empty(q);
    // clear_queue(q);
    // is_empty = is_queue_empty(q);

    // init_stack(stack);
    // push_stack(stack, 18);
    // push_stack(stack, 4);
    // push_stack(stack, 6);
    // push_stack(stack, 26);
    // push_stack(stack, 63);
    // peek_stack(stack);
    // pop_stack(stack);
    // swap(stack);
    // dup(stack);
    
    return (EXIT_SUCCESS);
}

