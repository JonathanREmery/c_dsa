#include "linked_list.h"

/**
 * Destroys a node
 * @param node The node to destroy
 */
void node_destroy(node_t* node) {
    // Free the memory allocated for the node
    free(node->value);
    free(node);
}

/**
 * Creates a linked list
 * @param element_size The size of the element in the list
 * @return The linked list
 */
linked_list_t* linked_list_create(uint64_t element_size) {
    // Allocate memory for the linked list
    linked_list_t* list = malloc(sizeof(linked_list_t));

    // Initialize the linked list
    list->element_size = element_size;
    list->num_nodes = 0;
    list->head = NULL;
    list->tail = NULL;

    // Return the linked list
    return list;
}

/**
 * Adds a value to the end of the list
 * @param list The linked list
 * @param value The value to add
 */
void linked_list_add(linked_list_t* list, void* value) {    
    // Check if the list or value is NULL
    if (!list || !value) {
        return;
    }

    // Allocate memory for the node
    node_t* node = malloc(sizeof(node_t));
    if (!node) return;

    // Allocate memory for the value
    node->value = malloc(list->element_size);
    if (!node->value) {
        free(node);
        return;
    }

    // Set the value and index of the node
    memcpy(node->value, value, list->element_size);
    node->index = list->num_nodes;
    node->next = NULL;

    // If the list is empty, set both head and tail to the new node
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        // Otherwise, add to the tail and update tail
        list->tail->next = node;
        list->tail = node;
    }

    // Increment the number of nodes in the list
    list->num_nodes++;
}

/**
 * Adds a value to the list at a specific index
 * @param list The linked list
 * @param value The value to add
 * @param index The index to add the value at
 */
void linked_list_add_at(linked_list_t* list, void* value, uint64_t index) {
    // Check if the insertion is possible
    if (!list || !value || index > list->num_nodes) {
        return;
    }

    // Allocate memory for the node
    node_t* node = malloc(sizeof(node_t));
    if (!node) return;

    // Allocate memory for the value
    node->value = malloc(list->element_size);
    if (!node->value) {
        free(node);
        return;
    }

    // Set the value and index of the node
    memcpy(node->value, value, list->element_size);
    node->index = index;

    // If the index is 0, insert the node at the head
    if (index == 0) {
        node->next = list->head;
        list->head = node;

        if (!list->tail) {
            list->tail = node;
        }

        list->num_nodes++;
        return;
    }

    // Iterate until the node before the index
    node_t* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    // Insert the node
    node->next = current->next;
    current->next = node;
    if (!node->next) {
        list->tail = node;
    }
    list->num_nodes++;
    
    // Update the indices of the nodes after
    current = node->next;
    while (current) {
        current->index++;
        current = current->next;
    }
}

/**
 * Removes a value from the list at a specific index
 * @param list The linked list
 * @param index The index to remove the value at
 */
void linked_list_remove_at(linked_list_t* list, uint64_t index) {
    // Check if removal is possible
    if (!list || !list->head || index >= list->num_nodes) {
        return;
    }

    // Initialize the node to remove
    node_t* to_remove;

    // Check if removing the head
    if (index == 0) {
        // Remove the head
        to_remove = list->head;
        list->head = list->head->next;

        // Set tail to NULL if needed
        if (!list->head) {
            list->tail = NULL;
        }
    } else {
        // Iterate until the node before the index
        node_t* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        // Remove the node
        to_remove = current->next;
        current->next = to_remove->next;

        // Set tail to the current node if needed
        if (!current->next) {
            list->tail = current;
        }
    }

    // Update the indices of the nodes after
    node_t* current = to_remove->next;
    while (current) {
        current->index--;
        current = current->next;
    }

    // Destroy the node and decrement the number of nodes
    node_destroy(to_remove);
    list->num_nodes--;
}

/**
 * Removes a value from the list
 * @param list The linked list
 */
void linked_list_remove(linked_list_t* list) {
    // Check if removal is possible
    if (!list || !list->head) {
        return;
    }

    // If there is only one node
    if (list->num_nodes == 1) {
        node_destroy(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->num_nodes = 0;
        return;
    }

    // Find the second to last node
    node_t* current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }

    // Remove the last node
    node_destroy(list->tail);
    list->tail = current;
    list->tail->next = NULL;
    list->num_nodes--;
}

/**
 * Destroys a linked list
 * @param list The linked list to destroy
 */
void linked_list_destroy(linked_list_t* list) {
    // Check if the list is NULL or empty
    if (!list || !list->head) return;

    // Free all nodes
    node_t* current = list->head;
    while (current != NULL) {
        node_t* next = current->next;
        node_destroy(current);
        current = next;
    }

    // Free the memory allocated for the linked list
    free(list);
}
