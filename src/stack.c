/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "stack.h"

/**
 * @brief Initialise la pile avec un index à -1
 * 
 * @param s Correspondant à une pile de structure Stack
 */
void init_stack(Stack *s)
{
    s->index = -1;
}

/**
 * @brief Ajoute une valeur à la pile en vérifiant si la pile
 * n'est pas déjà complète.
 * 
 * @param s Correspondant à une pile de structure Stack
 * @param value La value à ajouter à la pile
 */
void push(Stack *s, float value)
{
    if (s->index < (int) STACK_MAX_SIZE-1)
    {
        s->index++;
        s->data[s->index] = value;
    }
}

/**
 * @brief Extrait un élèment d'une pile
 * 
 * @param s Correspondant à une pile de structure Stack
 * @return float Retourne un float correspondant à l'élèment
 * retiré de la pile
 */
float pop(Stack *s)
{
    float val = s->data[s->index];
    s->index--;
    return val;
}

/**
 * @brief Vérfie si la pile est vide ou non
 * 
 * @param s Correspondant à une pile de structure Stack
 * @return true Si la pile est vide
 * @return false Si la pile n'est pas vide
 */
bool is_stack_empty(Stack *s)
{
    if (s->index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Renvoie la valeur au dessus de la pile
 * 
 * @param s Correspondant à une pile de structure Stack
 * @return float 
 */
float peek(Stack *s)
{ // aka top or front
    if(!is_stack_empty(s))
    {
        return s->data[s->index];
    }
    exit(EXIT_FAILURE);
}

/**
 * @brief Duplique le dernier élèment de la pile
 * 
 * @param s Correspondant à une pile de structure Stack
 */
void dup(Stack *s)
{
    if(!is_stack_empty(s) && s->index < (int) STACK_MAX_SIZE-1)
    {
        s->index++;
        s->data[s->index] = s->data[s->index-1];
    }
}

/**
 * @brief Inverse le dernier élèment de la pile avec l'avant dernier
 * 
 * @param s Correspondant à une pile de structure Stack
 */
void swap(Stack *s)
{
    float temp = s->data[s->index];
    s->data[s->index] = s->data[s->index-1];
    s->data[s->index-1] = temp;
}

/**
 * @brief Vide la pile en replacant l'index à son état d'origine.
 * Par conséquent les anciennes valeurs vont être écrasées par les nouvelles
 * 
 * @param s Correspondant à une pile de structure Stack
 */
void clear(Stack *s)
{
    s->index = -1;
}