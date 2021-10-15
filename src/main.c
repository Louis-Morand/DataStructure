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

void test_array_list()
{
    Array_list *array = (Array_list *)(malloc(sizeof(Array_list)));

    init_array_list(array);
    insert_at(array, 2, 56);
    CU_ASSERT(array->data[1] == 56);
    add(array, 99);
    CU_ASSERT(array->data[2] == 99);
    remove_at(array, 2);
    CU_ASSERT(array->data[1] == 99);
    CU_ASSERT((get_at(array, 2)) == 99);
    clear_array(array);
    CU_ASSERT(array->index == 0);
}
void test_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    init_queue(queue);
    CU_ASSERT(is_queue_empty(queue) == true);
    enqueue(queue, 5);
    CU_ASSERT((queue->data[queue->index - 1]) == 5);
    CU_ASSERT((front(queue)) == 5);
    enqueue(queue, 6);
    CU_ASSERT(queue->data[queue->index - 1] == 6);
    enqueue(queue, 990);
    CU_ASSERT(queue->data[queue->index - 1] == 990);
    CU_ASSERT((dequeue(queue)) == 5);
    CU_ASSERT(front(queue) == 6);
    CU_ASSERT(is_queue_empty(queue) == false);
    clear_queue(queue);
    CU_ASSERT(is_queue_empty(queue) == true);
}

void test_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    init_stack(stack);
    CU_ASSERT(is_stack_empty(stack) == true);
    push_stack(stack, 18);
    CU_ASSERT(stack->data[stack->index]);
    push_stack(stack, 4);
    CU_ASSERT(stack->data[stack->index] == 4);
    push_stack(stack, 63);
    CU_ASSERT(stack->data[stack->index] == 63);
    CU_ASSERT(peek_stack(stack) == 63);
    CU_ASSERT(pop_stack(stack) == 63);            // on enleve le 63, reste 18 et 4
    swap_stack(stack);                         // on echange le 18 et le 4
    CU_ASSERT((stack->data[stack->index]) == 18); // donc 18 est en position 2
    CU_ASSERT((stack->data[stack->index - 1]) == 4);
    dup_stack(stack);
    CU_ASSERT(stack->data[stack->index] == stack->data[stack->index - 1]);
}

void test_heap()
{
    Heap *heap = (Heap *)(malloc(sizeof(Heap)));

    init_heap(heap);
    CU_ASSERT(is_heap_empty(heap) == true);
    push_heap(heap, 55);
    CU_ASSERT(peek_heap(heap) == 55);
    push_heap(heap, 66);
    CU_ASSERT(heap->data[2] == 66);
    push_heap(heap, 89);
    CU_ASSERT(heap->data[2] == 89);
    CU_ASSERT(pop_heap(heap) == 55);    // pop the root value
    CU_ASSERT(replace(heap, 10) == 66); // pop root and push a new key.
    CU_ASSERT(peek_heap(heap) == 10);
    void clear_heap(Heap * h);
    CU_ASSERT(is_heap_empty(heap) == true);
}

int test_init()
{
    return 0;
}
int test_cleanup()
{
    return 0;
}


int main(int argc, char **argv)
{
    CU_initialize_registry();

    CU_pSuite *tests = CU_add_suite("tests DataStructure", test_init, test_cleanup);

    CU_add_test(tests, "test arrays_list", test_array_list);
    CU_add_test(tests, "test queue", test_queue);
    CU_add_test(tests, "test stack", test_stack);
    // CU_add_test(tests, "test heap", test_heap);
    
    CU_basic_run_tests();
    test_cleanup();
    return (EXIT_SUCCESS);
}
