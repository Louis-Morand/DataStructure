/**
 * @file heap.h
 * @author Aurelio LOURENCO, modification Louis MORAND, Benoit ARQUILLIERE
 * @brief 
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdbool.h>

#ifndef HEAP_H
#define HEAP_H

#define HEAP_MAX_SIZE 100

typedef struct
{
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;

#endif /* HEAP_H */

//main functions
void init_heap(Heap *h);
bool is_heap_empty(Heap *h);
float pop_heap(Heap *h); //pop the root value
void push_heap(Heap *h, float value);
float replace(Heap *h, float value); // pop root and push a new key.
float peek_heap(Heap *h);            // return root value but dont remove it
void clear_heap(Heap *h);

//utils functions
void swap(float a, float b);
void heapify(Heap *h, int size, int i);
void heapsort(Heap *h);