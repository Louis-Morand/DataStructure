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

typedef struct {
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;


#endif /* HEAP_H */

void init_heap(Heap *h);
bool is_heap_empty(Heap *h);
float pop_heap(Heap *h); //pop the root value
void push_heap(Heap *h, float value);
float replace(Heap *h, float value); // pop root and push a new key.
float peek_heap(Heap *h); // return root value but dont remove it
void clear_heap(Heap *h);

void swap(float *a, float *b);

/**
 * @brief tri les valeurs par avec le tri par tas
 * 
 * @param tab tableau float a trier
 * @param size taille du tableau
 * @param i 
 * @param sens_tri croissant ou décroissant
 */

void heapify(float *tab, int size, int i, int sens_tri);

/**
 * @brief tri les valeurs par avec le tri par tas
 * 
 * @param tab tableau float a trier
 * @param size taille du tableau
 * @param sens_tri croissant ou décroissant
 */
void heapsort(float *tab, int size, int sens_tri);

/**
 * @brief appel de la fonction test
 * 
 * @param test_number nombre de fois que le test va être réalisé
 * @param heap_results tableau contenant les résultats
 */
void heap_sorting_test(int test_number, float *heap_results);

//En option
//void heapify(Heap *s, float array[], size_t array_size); //create Heap from array
//void merge(Heap *dest, Heap *src); //merge src into dest


