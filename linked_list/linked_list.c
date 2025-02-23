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
 * @param list_size The size of the list
 * @return The linked list
 */
linked_list_t* linked_list_create(uint64_t element_size, uint64_t list_size) {
    // Allocate memory for the linked list
    linked_list_t* list = malloc(sizeof(linked_list_t));

    // Initialize the linked list
    list->element_size = element_size;
    list->list_size = list_size;
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
    // Allocate memory for the node
    node_t* node = malloc(sizeof(node_t));

    // Set the value of the node
    node->value = malloc(list->element_size);
    memcpy(node->value, value, list->element_size);

    // Set the index of the node
    node->index = list->num_nodes;

    // Set the next to NULL
    node->next = NULL;

    // If the tail is not NULL, set the next node of the tail to the new node
    if (list->tail != NULL) {
        list->tail->next = node;
        list->tail = node;
    }

    // If the head is NULL, set the head and tail to the new node
    if (list->head == NULL) {
        list->head = node;
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
    // Allocate memory for the node
    node_t* node = malloc(sizeof(node_t));

    // Set the value of the node
    node->value = malloc(list->element_size);
    memcpy(node->value, value, list->element_size);

    // Set the index of the node
    node->index = index;

    // Set the next to NULL
    node->next = NULL;

    // If the head is NULL, set the head and tail to the new node
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }

    // Iterate through the list
    node_t* current = list->head;
    bool inserted = false;
    while (current != NULL) {
        node_t* next = current->next;

        // Check if node should be inserted next
        if (current->index == index - 1 && next != NULL) {
            // Set the next node of the current node to the new node
            current->next = node;

            // Set the next node of the new node to the next node
            node->next = next;

            // Set the current node to the new node
            current = node->next;

            // Set the inserted flag, and increment the number of nodes in the list
            inserted = true;
            list->num_nodes++;
        }

        // If the node was inserted, increment the index of the current node and continue
        if (inserted) {
            current->index++;
            current = current->next;
            continue;
        }

        // Check if the next node is NULL
        if (next == NULL) {
            // If the node was inserted, break
            if (inserted) {
                break;
            }

            // Set the next node of the current node to the new node
            current->next = node;

            // Increment the number of nodes in the list and break
            list->num_nodes++;
            break;
        }

        // Set the current node to the next node
        current = next;
    }
}

/**
 * Removes a value from the list at a specific index
 * @param list The linked list
 * @param index The index to remove the value at
 */
void linked_list_remove_at(linked_list_t* list, uint64_t index) {
    // Initialize the current node, and removed flag
    node_t* current = list->head;
    bool removed = false;

    // Iterate through the list
    while (current != NULL) {
        // Get the next node
        node_t* next = current->next;

        // Check if the current node is the node to remove
        if (current->index == index - 1 && next != NULL) {
            // Set the next node of the current node to the next node of the next node
            current->next = next->next;

            // If the next node of the next node is not NULL, set the current node to the next node of the next node
            if (next->next != NULL) {
                current = next->next;
            }

            // Destroy the next node and set the removed flag
            node_destroy(next);
            removed = true;

            // Decrement the number of nodes in the list
            list->num_nodes--;
        }

        // If the node was removed, decrement the index of the current node and continue
        if (removed) {
            current->index--;
            current = current->next;
            continue;
        }

        // Set the current node to the next node
        current = next;
    }
}

/**
 * Removes a value from the list
 * @param list The linked list
 */
void linked_list_remove(linked_list_t* list) {
    // Initialize the current node
    node_t* node = list->head;

    // Iterate through the list
    while (node != NULL) {
        // Get the next node
        node_t* next = node->next;

        // Check if the next node is NULL
        if (next == NULL) {
            break;
        }

        // Check if the next node of the next node is NULL
        if (next->next == NULL) {
            // Set the next node of the current node to NULL and destroy the next node
            node->next = NULL;
            node_destroy(next);

            // Decrement the number of nodes in the list and break
            list->num_nodes--;
            break;
        }

        // Set the current node to the next node
        node = next;
    }
}

/**
 * Destroys a linked list
 * @param list The linked list to destroy
 */
void linked_list_destroy(linked_list_t* list) {
    // Initialize the current node
    node_t* node = list->head;

    // Iterate through the list
    while (node != NULL) {
        // Get the next node
        node_t* next = node->next;

        // Destroy the current node
        node_destroy(node);

        // Set the current node to the next node
        node = next;
    }

    // Free the memory allocated for the linked list
    free(list);
}
