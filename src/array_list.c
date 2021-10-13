/**
 * @file array_list.c
 * @author Louis MORAND, Benoit ARQUILLIERE
 * @brief Fonction groupant les actions réalisables sur une liste
 * @version 0.1
 * @date 2021-10-13
 * 
 * Sur une liste, l'acces aux elements est libre à partir de l'index connu
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

/*
typedef struct {
    float data[ARRAY_LIST_MAX_SIZE];
    int index;
} Array_list;
*/

/**
 * @brief Fonction d'initialisation du tableau de liste
 *
 * Prends en paramètre la structure Array_list, et initialise l'index à -1.
 * Une indexation de l'index à 0 permet d'augmenter l'index de 1 à chaque nouvel ajout,
 * permettant de mettre à jour la position à chaque ajout.
 * 
 * @param s Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 */
void init_array_list(Array_list *l){
    l->index = 0;
}

/**
 * @brief Fonction d'insertion dans le tableau
 * 
 * Prends en paramètre la structure Array_list, puis insère la valeur donnée à sa position donnée.
 * Pour cela, procède par décalage des valeurs du tableau vers la fin, puis met ensuite à jour l'index du tableau.
 * 
 * @param l L'ArrayList passée en paramètre
 * @param position la position à laquelle insérer la valeur
 * @param value la valeur à insérer dans le tableau
 */
void insert_at(Array_list *l, int position, float value){
    

}
void add(Array_list *l, float value);
float remove_at(Array_list *l, int position);
float get_at(Array_list *l,int position);
void clear(Array_list *l);
