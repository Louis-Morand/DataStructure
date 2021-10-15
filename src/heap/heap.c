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
    h->index = 0;
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
    //TODO: supprimer la valeur root
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
    // h->index++;
    // for (int i = h->index; i > 0; i--)
    // {
    //     h->data[i] = h->data[i-1];
    // }
    //
    // h->data[0] = value;
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
    pop_heap(h);
    push_heap(h, value);
    return value;
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
    h->index = 0;
}

// //En option
// void heapify(Heap *s, float array[], size_t array_size)
// {

// } //create Heap from array
// void merge(Heap *dest, Heap *src)
// {

// } //merge src into dest