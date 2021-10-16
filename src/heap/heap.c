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
 * @brief Echange deux valeurs,est utilisé par le tri par tas
 * 
 * @param a float
 * @param b float
 */
void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief tri les valeurs par avec le tri par tas
 * 
 * @param tab tableau float a trier
 * @param size taille du tableau
 * @param i 
 * @param sens_tri croissant ou décroissant
 */
void heapify(float *tab, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && (tab[left] > tab[largest]))
        largest = left;

    if (right < size && (tab[right] > tab[largest]))
        largest = right;

    if (largest != i)
    {
        swap(&tab[i], &tab[largest]);
        heapify(tab, size, largest);
    }
}

/**
 * @brief tri les valeurs par avec le tri par tas
 * 
 * @param tab tableau float a trier
 * @param size taille du tableau
 * @param sens_tri croissant ou décroissant
 */
void heapsort(float *tab, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(tab, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&tab[0], &tab[i]);
        heapify(tab, i, 0);
    }
}

/**
 * @brief Permet d'initialiser le tas
 *
 * @param h Le tas selectionné
 */
void init_heap(Heap *h)
{
    h->index = 0;
}

/**
 * @brief Vérifie si le tas est vide ou non
 *
 * @param h Le tas selectionné
 * @return true Le tas est vide
 * @return false Le tas n'est pas vide
 */
bool is_heap_empty(Heap *h)
{
    bool isEmpty = (h->index == 0);
    return isEmpty;
}

/**
 * @brief Permet de retirer la valeur la valeur en haut du tas et de la récupérer
 *
 * @param h Le tas selectionné
 * @return float La valeur en haut du tas
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
 * @brief Permet d'ajouter une valeur au tas
 *
 * @param h Le tas selectionné
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
    heapsort(h->data, h->index);
}

/**
 * @brief Permet de supprimer la valeur en haut du tas et d'ajouter une nouvelle valeur
 *
 * @param h Le tas selectionné
 * @param value La valeur a ajouter
 * @return float La valeur qui a été ajouté
 */
float replace(Heap *h, float value)
{
    pop_heap(h);
    push_heap(h, value);
    return value;
}

/**
 * @brief Permet de renvoyer la valeur en haut du tas
 *
 * @param h Le tas selectionné
 * @return float La valeur en haut du tas
 */
float peek_heap(Heap *h)
{
    return h->data[0];
}

/**
 * @brief Permet de réinitialiser le tas 
 *
 * @param h Le tas selectionné
 */
void clear_heap(Heap *h)
{
    h->index = 0;
}
