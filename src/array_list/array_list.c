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

/**
 * @brief Fonction d'initialisation du tableau de liste
 *
 * Prends en paramètre la structure Array_list, et initialise l'index à -1.
 * Une indexation de l'index à 0 permet d'augmenter l'index de 1 à chaque nouvel ajout,
 * permettant de mettre à jour la position à chaque ajout.
 *
 * @param s Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 */
void init_array_list(Array_list *l)
{
    l->index = 0;
}

/**
 * @brief Fonction d'insertion dans le tableau
 *
 * Prends en paramètre la structure Array_list, puis insère la valeur donnée à sa position donnée.
 * On vérifie d'abord si la valeur peut etre insérée sans décalage, sinon, 
 * on procède par décalage des valeurs du tableau à partir de la fin jusqu'a la position passée, puis met ensuite à jour l'index du tableau.
 * Pour chaque valeur ajoutée, on augmente la taille de l'index, qui correspond à la taille logique du tableau.
 * La fonction parcours le tableau à l'envers, en décalant les valeurs evrs la fin, et s'arrete avant la position passée en paremètre pour permettre l'insertion.
 * Vérifie si le tableau est plein auquel cas aucun ajout n'est possible.
 * On considère que l'insertion donne une position "humaine", cad que le tableau commence à 1 et non 0, donc on soustrait 1 pour obtenir la position "informatique"
 *
 * Egalement, une vérification plus poussée peut etre mise en place pour des index dépassants la taille du tableau
 * @param l L'ArrayList passée en paramètre
 * @param position la position à laquelle insérer la valeur
 * @param value la valeur à insérer dans le tableau
 */
void insert_at(Array_list *l, int position, float value)
{
    int pos_corrig = position - 1;

    if (l->index <= pos_corrig)
    {
        l->data[pos_corrig] = value;
    }
    else
    {
        for (int i = ARRAY_LIST_MAX_SIZE; i > pos_corrig; i--)
        {
            l->data[i] = l->data[i - 1];
        }
    }
    l->index = l->index + pos_corrig;
    l->data[pos_corrig] = value;
    l->index++;
}

/**
 * @brief Fonction d'insertion dans la liste
 *
 * Prends en paramètre la structure Array_list, puis insère la valeur donnée à la dernière position de la file
 * Pour chaque valeur ajoutée, on augmente la taille de l'index, qui correspond à la taille logique du tableau.
 *
 * Egalement, une vérification plus poussée peut etre mise en place pour des index dépassants la taille du tableau
 * @param l L'ArrayList passé en paramètre
 * @param value la valeur à insérer dans le tableau en dernière position
 */
void add(Array_list *l, float value)
{

    l->data[l->index] = value;
    l->index++;
}

// On considère que l'insertion donne une position "humaine", cad que le tableau commence à 1 et non 0, donc on soustrait 1 pour obtenir la position "informatique"

/**
 * @brief Fonction de renvoi de valeur à un index donné
 *
 * Retourne la valeur située à la position donnée, en l'enlevant du tableau.
 * On considère que la valeur passée en paramètre est une position "humaine" du taleau, soit de 1 à 100,
 * donc on soustrait 1 à cette valeur pour obtenir la valeur logique.
 * Une fois la valeur récupérée, on décale le tableau et décrémente l'index de manière à mettre à
 * jour le tableau.
 * Egalement, une vérification plus poussée peut etre mise en place pour des index dépassants la taille du tableau,
 * et une vérification et renvoi erreur si le tableau est vide.
 *
 * @param l L'ArrayList passé en paramètre
 * @param position La position de la valeur dans le tableau
 * @return float la valeur située précédemment à l'index donné
 */
float remove_at(Array_list *l, int position)
{
    int index = position - 1;

    float ret = l->data[index];

    for (int i = index; i < ARRAY_LIST_MAX_SIZE; i++)
    {
        l->data[i] = l->data[i + 1];
    }

    l->index--;

    return ret;
}

/**
 * @brief Fonction de "peek" à une position donnée
 *
 * Retourne une copie de la valeur située à la position donnée
 * On considère que la valeur passée en paramètre est une position "humaine" du taleau, soit de 1 à 100,
 * donc on soustrait 1 à cette valeur pour obtenir la valeur logique.
 * On ne fait que copier la valeur située à la position, donc il n'y a pas de suppression de valeurs
 * Egalement, une vérification plus poussée peut etre mise en place pour des index dépassants la taille du tableau,
 * ou bien une vérification si la position est vide ou non, avec l'inclusion d'une valeur "vide".
 *
 * @param l L'ArrayList passé en paramètre
 * @param position La position de la valeur dans le tableau
 * @return float la valeur située à l'index donné
 */
float get_at(Array_list *l, int position)
{
    int index = position - 1;
    float ret;

    ret = l->data[index];

    return ret;
}

// possible aussi de parcourir pour affecter une valeur qu'on considerera comme etant "vide" dans le tableau, mais plus rapide de simplement reset l'index
/**
 * @brief Fonction de réinitialisation du tableau
 *
 * Cette fonction permet de réinitialiser le tableau, en mettant la position de l'index à 0.
 * Egalement, une autre possibilité de "vidage" pourrait etre de remplir le tableau de valeurs considérées comme "nulles"
 *
 * @param l L'ArrayList passé en paramètre
 */
void clear_array(Array_list *l)
{
    l->index = 0;
}
