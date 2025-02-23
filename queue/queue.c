#include "queue.h"

/**
 * Create a new queue
 * @param element_size Size of each element in the queue
 * @param queue_size Maximum number of elements in the queue
 * @return Pointer to the queue
 */
queue_t* queue_create(uint64_t element_size, uint64_t queue_size) {
    // Allocate memory for the queue
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));

    // Initialize the queue
    queue->element_size = element_size;
    queue->queue_size = queue_size;
    queue->queued_elements = 0;
    queue->dequeued_elements = 0;
    queue->base = malloc(queue_size * element_size);
    queue->head = queue->base;
    queue->tail = queue->base;

    // Return the queue
    return queue;
}

/**
 * Grow the queue
 * @param queue Pointer to the queue
 */
void queue_grow(queue_t* queue) {
    // Double the size of the queue
    queue->queue_size *= 2;

    // Calculate the offsets
    uint64_t head_offset = queue->head - queue->base;
    uint64_t tail_offset = queue->tail - queue->base;

    // Reallocate the queue
    queue->base = realloc(queue->base, queue->queue_size * queue->element_size);

    // Update the queue
    queue->head = queue->base + head_offset;
    queue->tail = queue->base + tail_offset;
}

/**
 * Enqueue an element into the queue
 * @param queue Pointer to the queue
 * @param element Pointer to the element to enqueue
 */
void enqueue(queue_t* queue, void* element) {
    // Grow the queue if it is full
    if (queue->queued_elements == queue->queue_size) {
        queue_grow(queue);
    }

    // Copy the element into the queue
    memcpy(queue->tail, element, queue->element_size);

    // Update the queue
    queue->tail += queue->element_size;
    queue->queued_elements++;
}

/**
 * Dequeue an element from the queue
 * @param queue Pointer to the queue
 * @return Pointer to the element, NULL if the queue is empty
 */
void* dequeue(queue_t* queue) {
    // Return NULL if the queue is empty
    if (queue->queued_elements == queue->dequeued_elements) {
        return NULL;
    }

    // Grow the queue if it is full
    if (queue->queued_elements == queue->queue_size - 1) {
        queue_grow(queue);
        queue->head += queue->element_size;
        queue->tail += queue->element_size;
    }

    // Get the element
    void* element = queue->head;

    // Update the queue
    queue->head += queue->element_size;
    queue->dequeued_elements++;

    // Return the element
    return element;
}

/**
 * Destroy the queue
 * @param queue Pointer to the queue
 */
void queue_destroy(queue_t* queue) {
    // Free memory allocated for the queue
    free(queue->base);
    free(queue);
}