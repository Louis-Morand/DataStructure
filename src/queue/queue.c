/**
 * @file queue.c
 * @author Aurelio LOURENCO, modification Louis MORAND, Benoit ARQUILLIERE
 * @brief Fichier contenant les actions réalisables sur une file
 * @version 0.1
 * @date 2021-10-13
 *
 * Dans ce type de structure de données, les données rentrées sont considérées comme dans une file,
 * c'est à dire que chaque élément rajouté va aller en fin de liste (avec enqueue), et chaque élement
 * enlevé sera enlevé du début de la liste (avec dequeue), selon un principe FIFO (premier arrivé premier sorti)
 * Les opérations possibles sur ce type de liste sont l'initalisation (init_queue), l'ajout (enqueue),
 * la suppression de valeur (enqueue), la vérification de l'étatv de la liste (vide ou non) (avec is_queue_empty),
 * la vérifiaction de la première valeur de la file (avec front), et le vidage de la liste (avec clear_queue).
 */

#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

/**
 * @brief Fonction d'initialisation du tableau de file
 *
 * Prends en paramètre la structure Queue, et initialise l'index à -1.
 * Une indexation de l'index à 0 permet d'augmenter l'index de 1 à chaque nouvel ajout,
 * permettant de mettre à jour la position à chaque ajout.
 *
 * @param s Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 */
void init_queue(Queue *q)
{
    q->index = 0;
}

/**
 * @brief Fonction de rajout d'un élément dans la liste
 *
 * Le rajout d'un élément dans une file consiste à ajouter un élément en dernière position de la file,
 * puis à incrémenter l'index pour le placer sur la position suivante.
 *
 * On peux éventuellement inclure un avertissement et vérification au cas où le tableau serait plein
 *
 * @param q Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 * @param value La valeur à rajouter dans la file
 */
void enqueue(Queue *q, float value)
{

    q->data[q->index] = value;
    q->index++;
}

/**
 * @brief Fonction d'enlevement d'un element dans la liste
 *
 * L'enlevement d'un élement consiste à retourner l'elément en tete de liste, index 0, puis à décaler les valeurs du tableau
 * pour faire "avancer" la liste, en décalant 1 par 1 les valeurs présentes.
 * On peux éventuellement inclure une vérification et erreur si le tableau est vide.
 *
 * @param q Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 * @return La valeur qui etait en tete de liste
 */
float dequeue(Queue *q)
{
    int val_ret;

    val_ret = q->data[0];
    for (int i = 0; i < q->index; i++)
    {
        q->data[i] = q->data[i + 1];
    }
    return val_ret;
}

/**
 * @brief Fonction permettant de savoir si la liste est vide
 *
 * Cette fonction se base sur l'index pour savoir si le tableau est vide, en vérifiant si il est à 0
 * ou non. En effet, un tableau vide aura son index à 0 pour permettre de rentrer la première valeur, tandis
 * qu'un index != 0 signifiera que le tableau n'est pas vide.
 *
 * @param q Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 * @return true si la liste est vide, ou false sinon
 */
bool is_queue_empty(Queue *q)
{
    bool is_empty = false;

    if (q->index == 0)
    {
        is_empty = true;
    }
    return is_empty;
}

/**
 * @brief Fonction permettant de vérifier la valeur en tete de liste, aka peek
 *
 * Cette fonction regarde l'élément en tete de liste, à l'index 0, et le renvoie sans décaler la liste
 * On peux éventuellement inclure une vérification et erreur si le tableau est vide
 *
 * @param q Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 * @return L'element en tete de liste
 */
float front(Queue *q)
{
    int val_ret;

    val_ret = q->data[0];

    return val_ret;
}

/**
 * @brief Fonction permettant de vider la liste
 *
 * Cette fonction permettant de vider la liste, en positionnant l'index à la position 0 pour
 * permettre de réécrire dans le tableau à partir du début.
 *
 * @param q Structure Queue, constituée d'un tableau de float et d'un index de remplissage
 */
void clear_queue(Queue *q)
{
    q->index = 0;
}