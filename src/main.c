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
//#include "stack.h"
#include "queue.h"

float test(int a) {
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

}



int main(int argc, char** argv) {
    Queue *q;
    float val;
    bool is_empty;

    init_queue(q);

    is_empty = is_queue_empty(q);
    printf("\nVide :%d", is_empty);

    enqueue(q, 5);
    val = front(q);
    printf("Valeur de tete:%f", val);
    enqueue(q, 6);
    val = front(q);
    printf("Valeur de tete:%f", val);
    enqueue(q, 990);
    val = front(q);
    printf("Valeur de tete:%f", val);
    
    dequeue(q);
    val = front(q);
    printf("Valeur de tete:%f", val);

    is_empty = is_queue_empty(q);
    printf("\nVide2 :%d", is_empty);

    clear(q);
    is_empty = is_queue_empty(q);
    printf("\nVide2 :%d", is_empty);

    // Stack *stack = (Stack *)malloc(sizeof(Stack));
    // init_stack(stack);
    // push(stack, 18);
    // push(stack, 4);
    // push(stack, 6);
    // push(stack, 26);
    // push(stack, 63);
    // peek(stack);
    // pop(stack);
    // swap(stack);
    // dup(stack);
    
    return (EXIT_SUCCESS);
}

