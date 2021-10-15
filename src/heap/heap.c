/**
 * @file heap.c
 * @author Aurelio LOURENCO, modification Louis MORAND, Benoit ARQUILLIERE
 * @brief Fichier regroupant les actions réalisables sur un tas
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include "heap.h"

/**
 * @brief 
 * 
 * @param h 
 */
void init_heap(Heap *h)
{
    h->index = -1;
}

/**
 * @brief 
 * 
 * @param h 
 * @return true 
 * @return false 
 */
bool is_heap_empty(Heap *h)
{
    bool isEmpty = h->index == -1;
    return isEmpty;
}

/**
 * @brief 
 * 
 * @param h 
 * @return float 
 */
float pop_heap(Heap *h)
{
    float val;
    return val;
}

/**
 * @brief 
 * 
 * @param h 
 * @param value 
 */
void push_heap(Heap *h, float value)
{
    h->index++;
    //TODO: add a value to heap
}

/**
 * @brief 
 * 
 * @param h 
 * @param value 
 * @return float 
 */
float replace(Heap *h, float value)
{
    float val;
    //TODO: pop root and push a new key.
    return val;
}

/**
 * @brief return root value but dont remove it
 * 
 * @param h 
 * @return float 
 */
float peek_heap(Heap *h)
{
    return h->data[0];
}

/**
 * @brief 
 * 
 * @param h 
 */
void clear_heap(Heap *h)
{
    h->index = -1;
}

// //En option
// void heapify(Heap *s, float array[], size_t array_size)
// {

// } //create Heap from array
// void merge(Heap *dest, Heap *src)
// {

// } //merge src into dest