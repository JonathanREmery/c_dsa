#include "deque.h"

/**
 * Create a new deque
 * @param element_size Size of the elements in the deque
 * @param deque_size Size of the deque
 */
deque_t* deque_create(uint64_t element_size, uint64_t deque_size) {
    // Allocate memory for the deque
    deque_t* deque = malloc(sizeof(deque_t));

    // Initialize the deque
    deque->element_size = element_size;
    deque->deque_size = deque_size;
    deque->elements = 0;
    deque->base = malloc(deque_size * element_size);
    deque->head = deque->base + deque->element_size * ((deque->deque_size / 2) - 1);
    deque->tail = deque->head + deque->element_size;

    // Return the deque
    return deque;
}

/**
 * Grow the deque
 * @param deque Pointer to the deque
 */
void deque_grow(deque_t* deque) {
    // Double the size of the deque
    deque->deque_size *= 2;

    // Calculate the offsets of the head and tail
    uint64_t head_offset = deque->head - deque->base;
    uint64_t tail_offset = deque->tail - deque->base;

    // Reallocate the memory for the deque
    deque->base = realloc(deque->base, deque->deque_size * deque->element_size);

    // Calculate the new offsets of the head and tail
    uint64_t new_head_offset = (deque->element_size * ((deque->deque_size / 2) - 1)) - (deque->element_size * (deque->elements / 2));
    uint64_t new_tail_offset = new_head_offset + (tail_offset - head_offset);

    // Reposition the elements in the deque
    memcpy(deque->base + new_head_offset, deque->base + head_offset, tail_offset - head_offset);

    // Update the head and tail
    deque->head = deque->base + new_head_offset;
    deque->tail = deque->base + new_tail_offset;
}

/**
 * Push an element to the front of the deque
 * @param deque Pointer to the deque
 * @param element Pointer to the element to push
 */
void deque_push_front(deque_t* deque, void* element) {
    // If the head is at the base of the deque, grow the deque
    if (deque->head == deque->base) {
        deque_grow(deque);
    }

    // Copy the element to the head
    memcpy(deque->head, element, deque->element_size);

    // Update the deque
    deque->head -= deque->element_size;
    deque->elements++;
}

/**
 * Push an element to the back of the deque
 * @param deque Pointer to the deque
 * @param element Pointer to the element to push
 */
void deque_push_back(deque_t* deque, void* element) {
    // If the tail is at the end of the deque, grow the deque
    if (deque->tail == deque->base + deque->deque_size * deque->element_size) {
        deque_grow(deque);
    }

    // Copy the element to the tail
    memcpy(deque->tail, element, deque->element_size);

    // Update the deque
    deque->tail += deque->element_size;
    deque->elements++;
}

/**
 * Pop an element from the front of the deque
 * @param deque Pointer to the deque
 */
void* deque_pop_front(deque_t* deque) {
    // If the deque is empty, return NULL
    if (deque->elements == 0) {
        return NULL;
    }

    // Update the head
    deque->head += deque->element_size;

    // Get the element
    void* element = malloc(deque->element_size);
    memcpy(element, deque->head, deque->element_size);

    // Update the deque
    deque->elements--;

    // Return the element
    return element;
}

/**
 * Pop an element from the back of the deque
 * @param deque Pointer to the deque
 */
void* deque_pop_back(deque_t* deque) {
    // If the deque is empty, return NULL
    if (deque->elements == 0) {
        return NULL;
    }

    // Update the tail
    deque->tail -= deque->element_size;

    // Get the element
    void* element = malloc(deque->element_size);
    memcpy(element, deque->tail, deque->element_size);

    // Update the deque
    deque->elements--;

    // Return the element
    return element;
}

/**
 * Peek at the front of the deque
 * @param deque Pointer to the deque
 */
void* deque_peek_front(deque_t* deque) {
    // If the deque is empty, return NULL
    if (deque->elements == 0) {
        return NULL;
    }

    // Return the element
    return deque->head + deque->element_size;
}

/**
 * Peek at the back of the deque
 * @param deque Pointer to the deque
 */
void* deque_peek_back(deque_t* deque) {
    // If the deque is empty, return NULL
    if (deque->elements == 0) {
        return NULL;
    }

    // Return the element
    return deque->tail - deque->element_size;
}

/**
 * Destroy the deque
 * @param deque Pointer to the deque
 */
void deque_destroy(deque_t* deque) {
    // Free the memory for the deque
    free(deque->base);
    free(deque);
}