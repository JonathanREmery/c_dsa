#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

// Test the linked_list_create function
void test_linked_list_create() {
    linked_list_t* list = linked_list_create(sizeof(int), 10);
    assert(list != NULL);
    assert(list->element_size == sizeof(int));
    assert(list->list_size == 10);
    assert(list->num_nodes == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    linked_list_destroy(list);
}

// Test the linked_list_add function
void test_linked_list_add() {
    linked_list_t* list = linked_list_create(sizeof(int), 10);
    int value = 10;
    linked_list_add(list, &value);
    assert(list->num_nodes == 1);
    assert(*(int*)list->head->value == value);
    assert(list->head == list->tail);
    linked_list_destroy(list);
}

// Test adding multiple values
void test_multiple_adds() {
    linked_list_t* list = linked_list_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    assert(list->num_nodes == 5);
    
    node_t* current = list->head;
    for (int i = 0; i < 5; i++) {
        assert(*(int*)current->value == values[i]);
        assert(current->index == i);
        current = current->next;
    }
    
    linked_list_destroy(list);
}

// Test adding at specific index
void test_add_at() {
    linked_list_t* list = linked_list_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    int insert_value = 100;
    linked_list_add_at(list, &insert_value, 2);
    assert(list->num_nodes == 6);
    
    node_t* current = list->head;
    assert(*(int*)current->value == 1);
    current = current->next;
    assert(*(int*)current->value == 2);
    current = current->next;
    assert(*(int*)current->value == 100);
    current = current->next;
    assert(*(int*)current->value == 3);
    
    linked_list_destroy(list);
}

// Test removing from end of list
void test_remove() {
    linked_list_t* list = linked_list_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    linked_list_remove(list);
    assert(list->num_nodes == 4);
    
    node_t* current = list->head;
    for (int i = 0; i < 4; i++) {
        assert(*(int*)current->value == values[i]);
        assert(current->index == i);
        current = current->next;
    }
    
    linked_list_remove(list);
    assert(list->num_nodes == 3);
    
    current = list->head;
    for (int i = 0; i < 3; i++) {
        assert(*(int*)current->value == values[i]);
        assert(current->index == i);
        current = current->next;
    }
    
    linked_list_destroy(list);
}


// Test removing at specific index
void test_remove_at() {
    linked_list_t* list = linked_list_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    linked_list_remove_at(list, 2);
    assert(list->num_nodes == 4);
    
    node_t* current = list->head;
    assert(*(int*)current->value == 1);
    assert(current->index == 0);
    current = current->next;
    assert(*(int*)current->value == 2);
    assert(current->index == 1);
    current = current->next;
    assert(*(int*)current->value == 4);
    assert(current->index == 2);
    current = current->next;
    assert(*(int*)current->value == 5);
    assert(current->index == 3);
    
    linked_list_destroy(list);
}

// Test linked list behavior
int main() {
    // Run tests
    test_linked_list_create();
    test_linked_list_add();
    test_multiple_adds();
    test_add_at();
    test_remove();
    test_remove_at();

    printf("[LINKED LIST] Tests completed successfully.\n");

    return 0;
}
