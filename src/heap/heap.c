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
    bool isEmpty = h->index == 0;
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
    float val = h->data[0];

    for (int i = 0; i < (h->index); i++)
    {
        h->data[i] = h->data[i + 1];
    }
    h->index--;
    
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
    for (int i = h->index; i > 0; i--)
    {
        h->data[i] = h->data[i-1];
    }
    
    h->data[0] = value;
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


// /**
//  * @brief 
//  * 
//  * @param a 
//  * @param b 
//  */
// void swap(float *a, float *b)
// {
//     float temp = *a;
//     *a = *b;
//     *b = temp;
// }

// /**
//  * @brief tri les valeurs par avec le tri par tas
//  * 
//  * @param tab tableau float a trier
//  * @param size taille du tableau
//  * @param i 
//  * @param sens_tri croissant ou décroissant
//  */
// void heapify(float *tab, int size, int i, int sens_tri)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < size && (tab[left] > tab[largest]) ^ !sens_tri) //opérateur XOR ^, 1+1 =1
//         largest = left;

//     if (right < size && (tab[right] > tab[largest]) ^ !sens_tri)
//         largest = right;

//     if (largest != i)
//     {
//         swap(&tab[i], &tab[largest]);
//         heapify(tab, size, largest, sens_tri);
//     }
// }

// /**
//  * @brief tri les valeurs par avec le tri par tas
//  * 
//  * @param tab tableau float a trier
//  * @param size taille du tableau
//  * @param sens_tri croissant ou décroissant
//  */
// void heapsort(float *tab, int size, int sens_tri)
// {
//     for (int i = size / 2 - 1; i >= 0; i--)
//     {
//         heapify(tab, size, i, sens_tri);
//     }
//     for (int i = size - 1; i >= 0; i--)
//     {
//         swap(&tab[0], &tab[i]);
//         heapify(tab, i, 0, sens_tri);
//     }
// }

// // //En option
// // void heapify(Heap *s, float array[], size_t array_size)
// // {

// // } //create Heap from array
// // void merge(Heap *dest, Heap *src)
// // {

// // } //merge src into dest