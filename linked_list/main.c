#include <stdio.h>

#include "linked_list.h"

// Test the linked list
int main() {
    // Create a linked list
    linked_list_t* list = linked_list_create(sizeof(int));

    // Add 10 values to the list
    for (int i = 0; i < 10; i++) {
        linked_list_add(list, &i);
    }

    // Add a value at index 4
    int value = 100;
    linked_list_add_at(list, &value, 4);

    // Add a value at index 7
    value *= 2;
    linked_list_add_at(list, &value, 7);

    // Remove the value at index 5
    linked_list_remove_at(list, 5);

    // Remove the value at index 9
    linked_list_remove_at(list, 9);

    // Print the list
    node_t* node = list->head;
    while (node != NULL) {
        printf("%lu | %d\n", node->index, *(int*)node->value);
        node = node->next;
    }

    // Destroy the list
    linked_list_destroy(list);

    return 0;
}