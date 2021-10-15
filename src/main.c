/**
 * @file main.c
 * @author Aurelio LOURENCO, modification Louis MORAND, Benoit ARQUILLIERE
 * @brief Tp de test d'implémentation de différent types de listes
 *
 * @version 0.1
 * @date 2021-10-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Console.h>
#include "./stack/stack.h"
#include "./queue/queue.h"
#include "./array_list/array_list.h"
#include "./heap/heap.h"

/**
 * @mainpage Datastructure Documentation
 * 
 * @brief Documentation du projet DataStructure, qui vise à implémenter et manipuler des structures de données
 * 
 * Le but de ce Tp est d'implémenter quatre types de structures de données:
 * Une pile, une file, une liste, et un tas.
 * 
 * Et d'exercer différentes manipulations de leurs données, telle que l'ajout, l'initialisation,
 * l'ajout en début ou fin de liste, et le remplacement de valeurs.
 * 
 * Actuellement, pour des mesures de simplicité, les types de tris sont implémentés via des tableaux,
 * Une modification future pourrait etre de passer via la véritable forme de leurs implémentations, ou
 * pour cette implémentation, de vérifier, en cas d'ajout de nouvelle valeur, si le tableau n'est pas deja plein.
 * 
 * 
 */
/*
TODO: TEST_CLEANUP ET TEST_INIT
CU_INITIALIZE_REGISTERY POUR INIT
CU_pSuite *p = CU_add_suite("test", test_init, test_cleanup);
CU_add_test(p,"NOMTEST", NOMTESTFONCTION);
CU_basic_run_tests(); pour run

*/

void test_array_list(Array_list *liste)
{
    init_array_list(liste);
    insert_at(liste, 2, 56);
    assert(liste->data[1] == 56);
    add(liste, 99);
    assert(liste->data[2] == 99);
    remove_at(liste, 2);
    assert(liste->data[1] == 99);
    assert((get_at(liste, 2)) == 99);
    clear_array(liste);
    assert(liste->index == 0);
}
void test_queue(Queue *queue)
{
    init_queue(queue);
    assert(is_queue_empty(queue) == true);
    enqueue(queue, 5);
    assert((queue->data[queue->index - 1]) == 5);
    assert((front(queue)) == 5);
    enqueue(queue, 6);
    assert(queue->data[queue->index - 1] == 6);
    enqueue(queue, 990);
    assert(queue->data[queue->index - 1] == 990);
    assert((dequeue(queue)) == 5);
    assert(front(queue) == 6);
    assert(is_queue_empty(queue) == false);
    clear_queue(queue);
    assert(is_queue_empty(queue) == true);
}

void test_stack(Stack *stack)
{

    init_stack(stack);
    assert(is_stack_empty(stack) == true);
    push_stack(stack, 18);
    assert(stack->data[stack->index]);
    push_stack(stack, 4);
    assert(stack->data[stack->index] == 4);
    push_stack(stack, 63);
    assert(stack->data[stack->index] == 63);
    assert(peek_stack(stack) == 63);
    assert(pop_stack(stack) == 63);            // on enleve le 63, reste 18 et 4
    swap_stack(stack);                         // on echange le 18 et le 4
    assert((stack->data[stack->index]) == 18); // donc 18 est en position 2
    assert((stack->data[stack->index - 1]) == 4);
    dup_stack(stack);
    assert(stack->data[stack->index] == stack->data[stack->index - 1]);
}

void test_heap(Heap *heap)
{
    init_heap(heap);
    assert(is_heap_empty(heap) == true);
    push_heap(heap,55);
    assert(peek_heap(heap)== 55);
    push_heap(heap, 66);
    assert(heap->data[2]==66);
    push_heap(heap,89);
    assert(heap->data[2]==89);
    assert(pop_heap(heap)==55); // pop the root value
    assert(replace(heap,10)==66);// pop root and push a new key.
    assert(peek_heap(heap)==10);
    void clear_heap(Heap * h);
    assert(is_heap_empty(heap) == true);
}


int main(int argc, char **argv)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    Array_list *array = (Array_list *)(malloc(sizeof(Array_list)));
    Heap *heap = (Heap *)(malloc(sizeof(Heap)));

    test_array_list(array);
    test_queue(queue);
    test_stack(stack);
    // test_heap(heap);
    

    return (EXIT_SUCCESS);
}
