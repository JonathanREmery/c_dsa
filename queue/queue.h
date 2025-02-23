#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * Queue structure
 */
typedef struct {
    uint64_t element_size;         // Size of each element in the queue
    uint64_t queue_size;           // Maximum number of elements in the queue
    uint64_t elements;             // Number of elements in the queue
    void*    base;                 // Pointer to the base of the queue
    void*    head;                 // Pointer to the head of the queue
    void*    tail;                 // Pointer to the tail of the queue
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
void queue_enqueue(queue_t* queue, void* element);

/**
 * Dequeue an element from the queue
 * @param queue Pointer to the queue
 * @return Pointer to the element, NULL if the queue is empty
 */
void* queue_dequeue(queue_t* queue);

/**
 * Peek at the element at the head of the queue
 * @param queue Pointer to the queue
 * @return Pointer to the element, NULL if the queue is empty
 */
void* queue_peek(queue_t* queue);

/**
 * Destroy the queue
 * @param queue Pointer to the queue
 */
void queue_destroy(queue_t* queue);

#endif