#ifndef DEQUE_H
#define DEQUE_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Deque structure
 */
typedef struct {
    uint64_t element_size; // Size of the elements in the deque
    uint64_t deque_size;   // Size of the deque
    uint64_t elements;     // Number of elements in the deque
    void*    base;         // Base pointer of the deque
    void*    head;         // Head pointer of the deque
    void*    tail;         // Tail pointer of the deque
} deque_t;

/**
 * Create a new deque
 * @param element_size Size of the elements in the deque
 * @param deque_size Size of the deque
 */
deque_t* deque_create(uint64_t element_size, uint64_t deque_size);

/**
 * Grow the deque
 * @param deque Pointer to the deque
 */
void deque_grow(deque_t* deque);

/**
 * Push an element to the front of the deque
 * @param deque Pointer to the deque
 * @param element Pointer to the element to push
 */
void deque_push_front(deque_t* deque, void* element);

/**
 * Push an element to the back of the deque
 * @param deque Pointer to the deque
 * @param element Pointer to the element to push
 */
void deque_push_back(deque_t* deque, void* element);

/**
 * Pop an element from the front of the deque
 * @param deque Pointer to the deque
 */
void* deque_pop_front(deque_t* deque);

/**
 * Pop an element from the back of the deque
 * @param deque Pointer to the deque
 */
void* deque_pop_back(deque_t* deque);

/**
 * Peek at the front of the deque
 * @param deque Pointer to the deque
 */
void* deque_peek_front(deque_t* deque);

/**
 * Peek at the back of the deque
 * @param deque Pointer to the deque
 */
void* deque_peek_back(deque_t* deque);

/**
 * Destroy the deque
 * @param deque Pointer to the deque
 */
void deque_destroy(deque_t* deque);

#endif
