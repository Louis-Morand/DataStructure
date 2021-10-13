/**
 * @file queue.h
 * @author Aurelio LOURENCO, modification Louis MORAND, Benoit ARQUILLIERE
 * @brief 
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H


#define QUEUE_MAX_SIZE 100

typedef struct {
    float data[QUEUE_MAX_SIZE];
    int index;
} Queue;


#endif /* QUEUE_H */

void init_queue(Queue *q);
void enqueue(Queue *q, float value);
float dequeue(Queue *q);

bool is_queue_empty(Queue *q);
float front(Queue *q); //aka peek
void clear_queue(Queue *q);

