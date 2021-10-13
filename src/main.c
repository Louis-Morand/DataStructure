/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <CUnit/CUnit.h>

#include "stack.h"

float test(int a) {
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

}


/*
 * 
 */
int main(int argc, char** argv) {

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

