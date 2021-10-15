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
 * Pour cela, on procède par décalage des valeurs du tableau à partir de la fin jusqu'a la position passée, puis met ensuite à jour l'index du tableau.
 * Pour chaque valeur ajoutée, on augmente la taille de l'index, qui correspond à la taille logique du tableau.
 * La fonction parcours le tableau à l'envers, en décalant les valeurs evrs la fin, et s'arrete avant la position passée en paremètre pour permettre l'insertion.
 * Vérifie si le tableau est plein auquel cas aucun ajout n'est possible.
 * On considère que l'insertion donne une position "humaine", cad que le tableau commence à 1 et non 0, donc on soustrait 1 pour obtenir la position "informatique"
 * @param l L'ArrayList passée en paramètre
 * @param position la position à laquelle insérer la valeur
 * @param value la valeur à insérer dans le tableau
 */
void insert_at(Array_list *l, int position, float value){
    int index=position-1;

    if(l->index>99){
        printf("Tableau plein");
    }
    for(int i=ARRAY_LIST_MAX_SIZE; i>index;i--){
        l->data[i]=l->data[i-1];
    }
    l->data[index] = value;
    l->index++;

}
//insère en fin(ou en debut ?) de tableau, TODO: VERIFIER DEBUT OU FIN
void add(Array_list *l, float value){

    if(l->index>99){
        printf("Tableau plein");
    }
    //INSERTION EN DERNIERE POSITION 
    l->data[l->index]=value;
    l->index++;

    //INSERTION EN PREMIERE POSITION
    for(int i=ARRAY_LIST_MAX_SIZE; i>0;i--){
        l->data[i]=l->data[i-1];
    }
    l->data[0]=value;
    l->index++;
}

//On considère que l'insertion donne une position "humaine", cad que le tableau commence à 1 et non 0, donc on soustrait 1 pour obtenir la position "informatique"

float remove_at(Array_list *l, int position){
    int index=position-1;

    if(position>99){
        printf("Erreur, position impossible");
    }
    float ret = l->data[index];

    for(int i=index; i<ARRAY_LIST_MAX_SIZE;i++){
        l->data[i]=l->data[i+1];
    }

    l->index--;

    return ret;
}

//On considère que l'insertion donne une position "humaine", cad que le tableau commence à 1 et non 0, donc on soustrait 1 pour obtenir la position "informatique"
float get_at(Array_list *l,int position){
    int index=position-1;
    float ret;

    if(position>99){
        printf("Erreur, position impossible");
    }
    ret = l->data[index];

    return ret;
}

//possible aussi de parcourir pour affecter une valeur qu'on considerera comme etant "vide" dans le tableau, mais plus rapide de simplement reset l'index
void clear(Array_list *l){
    l->index=0;
}
