#include <stdio.h>

#include "deque.h"

// Test the deque
int main() {
    // Create a deque
    deque_t* deque = deque_create(sizeof(int), 6);

    // Push elements to the front
    for (int i = 3; i > 0; i--) {
        deque_push_front(deque, &i);
    }

    // Push elements to the back
    for (int i = 4; i <= 6; i++) {
        deque_push_back(deque, &i);
    }

    // Pop all elements
    for (int i = 0; i < 6; i++) {
        printf("%d\n", *(int*)deque_pop_front(deque));
    }

    // Print the deque size and elements
    printf("dequeue size: %zu\n", deque->deque_size);
    printf("dequeue elements: %zu\n", deque->elements);

    // Destroy the deque
    deque_destroy(deque);
    return 0;
}