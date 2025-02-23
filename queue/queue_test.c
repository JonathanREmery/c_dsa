#include <assert.h>
#include <stdio.h>

#include "queue.h"

// Test the queue_create function
void test_queue_create() {
    queue_t* queue = queue_create(sizeof(int), 10);
    assert(queue != NULL);
    assert(queue->element_size == sizeof(int));
    assert(queue->queue_size == 10);
    assert(queue->elements == 0);
    queue_destroy(queue);
}

// Test the enqueue function
void test_enqueue() {
    queue_t* queue = queue_create(sizeof(int), 10);
    int value = 10;
    queue_enqueue(queue, &value);
    assert(queue->elements == 1);
    assert(*(int*)queue->head == value);
    queue_destroy(queue);
}

// Test the dequeue function
void test_dequeue() {
    queue_t* queue = queue_create(sizeof(int), 10);
    int value = 10;
    queue_enqueue(queue, &value);
    int* dequeued_value = (int*)queue_dequeue(queue);
    assert(*dequeued_value == value);
    assert(queue->elements == 0);
    queue_destroy(queue);
}

// Test the queue_destroy function
void test_queue_destroy() {
    queue_t* queue = queue_create(sizeof(int), 10);
    queue_destroy(queue);
}

// Test dequeue behavior when the queue is empty
void test_dequeue_empty() {
    queue_t* queue = queue_create(sizeof(int), 10);
    void* value = queue_dequeue(queue);
    assert(value == NULL);
    queue_destroy(queue);
}

// Test enqueue behavior when the queue is full (should trigger queue_grow)
void test_queue_grow() {
    queue_t* queue = queue_create(sizeof(int), 10);
    for (int i = 0; i < 11; i++) {
        queue_enqueue(queue, &i);
    }
    assert(queue->elements == 11);
    assert(queue->queue_size == 20);
    queue_destroy(queue);
}

// Test FIFO behavior with multiple enqueue/dequeue operations
void test_queue_fifo() {
    queue_t* queue = queue_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, &values[i]);
    }
    for (int i = 0; i < 5; i++) {
        int* dequeued = (int*)queue_dequeue(queue);
        assert(*dequeued == values[i]);
    }
    queue_destroy(queue);
}

// Test the peek function
void test_queue_peek() {
    queue_t* queue = queue_create(sizeof(int), 10);
    int value = 10;
    queue_enqueue(queue, &value);
    assert(*(int*)queue_peek(queue) == value);
    queue_destroy(queue);
}

// Test queue behavior
int main() {
    printf("[QUEUE] Running tests...\n");

    // Run tests
    test_queue_create();
    test_enqueue();
    test_dequeue();
    test_queue_destroy();
    test_dequeue_empty();
    test_queue_grow();
    test_queue_fifo();
    test_queue_peek();

    printf("[QUEUE] Tests completed successfully.\n");

    return 0;
}
