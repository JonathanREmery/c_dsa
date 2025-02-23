#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * Queue structure
 */
typedef struct {
    uint64_t element_size;
    uint64_t queue_size;
    uint64_t queued_elements;
    uint64_t dequeued_elements;
    void* base;
    void* head;
    void* tail;
} queue_t;

/**
 * Create a new queue
 * @param element_size Size of each element in the queue
 * @param queue_size Maximum number of elements in the queue
 * @return Pointer to the queue
 */
queue_t* queue_create(uint64_t element_size, uint64_t queue_size);

/**
 * Grow the queue
 * @param queue Pointer to the queue
 */
void queue_grow(queue_t* queue);

/**
 * Enqueue an element into the queue
 * @param queue Pointer to the queue
 * @param element Pointer to the element to enqueue
 */
void enqueue(queue_t* queue, void* element);

/**
 * Dequeue an element from the queue
 * @param queue Pointer to the queue
 * @return Pointer to the element, NULL if the queue is empty
 */
void* dequeue(queue_t* queue);

/**
 * Destroy the queue
 * @param queue Pointer to the queue
 */
void queue_destroy(queue_t* queue);

#endif