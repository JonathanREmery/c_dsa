#include <stdio.h>

#include "queue.h"

// Test the queue
int main() {
    // Create a queue of 10 integers
    queue_t* queue = queue_create(sizeof(int), 10);

    // Enqueue 10 elements
    for (int i = 0; i < 10; i++) {
        enqueue(queue, &i);
    }

    // Dequeue 10 elements
    for (int i = 0; i < 10; i++) {
        int* value = (int*)dequeue(queue);

        if (value != NULL) {
            printf("%d\n", *value);
        }
    }

    // Destroy the queue
    queue_destroy(queue);

    // Create a queue of 10 strings
    queue = queue_create(sizeof(char*), 10);

    // Enqueue 4 strings
    char* strings[] = {"AAA", "BBB", "CCC", "DDD"};
    for (int i = 0; i < 4; i++) {
        enqueue(queue, strings[i]);
    }

    // Dequeue 4 strings
    for (int i = 0; i < 4; i++) {
        char* value = (char*)dequeue(queue);

        if (value != NULL) {
            printf("%s\n", value);
        }
    }

    // Destroy the queue
    queue_destroy(queue);
    return 0;
}