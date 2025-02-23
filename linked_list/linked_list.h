#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Node structure
struct node;
typedef struct node node_t;

struct node {
    void*    value; // The value of the node
    uint64_t index; // The index of the node
    node_t*  next;  // The next node in the list
};

// Linked list structure
typedef struct {
    uint64_t element_size; // The size of the element in the list
    uint64_t list_size;    // The size of the list
    uint64_t num_nodes;    // The number of nodes in the list
    node_t*  head;         // The head of the list
    node_t*  tail;         // The tail of the list
} linked_list_t;

/**
 * Destroys a node  
 * @param node The node to destroy
 */
void node_destroy(node_t* node);

/**
 * Creates a linked list
 * @param element_size The size of the element in the list
 * @param list_size The size of the list
 * @return The linked list
 */
linked_list_t* linked_list_create(uint64_t element_size, uint64_t list_size);

/**
 * Adds a value to the end of the list
 * @param list The linked list
 * @param value The value to add
 */
void linked_list_add(linked_list_t* list, void* value);

/**
 * Adds a value to the list at a specific index
 * @param list The linked list
 * @param value The value to add
 * @param index The index to add the value at
 */
void linked_list_add_at(linked_list_t* list, void* value, uint64_t index);

/**
 * Removes a value from the list
 * @param list The linked list
 */
void linked_list_remove(linked_list_t* list);

/**
 * Removes a value from the list at a specific index
 * @param list The linked list
 * @param index The index to remove the value at
 */
void linked_list_remove_at(linked_list_t* list, uint64_t index);

/**
 * Destroys a linked list
 * @param list The linked list to destroy
 */
void linked_list_destroy(linked_list_t* list);

#endif
