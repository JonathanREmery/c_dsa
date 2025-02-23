#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

// Test structure for complex data type testing
typedef struct {
    int id;
    char name[50];
} test_struct_t;

// Test the linked_list_create function with various element sizes
void test_linked_list_create() {
    linked_list_t* int_list = linked_list_create(sizeof(int));
    linked_list_t* char_list = linked_list_create(sizeof(char));
    linked_list_t* struct_list = linked_list_create(sizeof(test_struct_t));
    
    assert(int_list != NULL);
    assert(int_list->element_size == sizeof(int));
    assert(int_list->num_nodes == 0);
    assert(int_list->head == NULL);
    assert(int_list->tail == NULL);
    
    assert(char_list != NULL);
    assert(char_list->element_size == sizeof(char));
    assert(char_list->num_nodes == 0);
    
    assert(struct_list != NULL);
    assert(struct_list->element_size == sizeof(test_struct_t));
    assert(struct_list->num_nodes == 0);
    
    linked_list_destroy(int_list);
    linked_list_destroy(char_list);
    linked_list_destroy(struct_list);
    
    linked_list_t* zero_list = linked_list_create(0);
    assert(zero_list != NULL);
    assert(zero_list->element_size == 0);
    linked_list_destroy(zero_list);
}

// Test edge cases for add operation
void test_edge_cases_add() {
    linked_list_t* list = linked_list_create(sizeof(int));
    int value = 42;
    
    linked_list_add(NULL, &value);
    linked_list_add(list, NULL);
    assert(list->num_nodes == 0);
    
    linked_list_destroy(list);
}

// Test the linked_list_add function with different data types
void test_linked_list_add() {
    linked_list_t* int_list = linked_list_create(sizeof(int));
    int value = 10;
    linked_list_add(int_list, &value);
    assert(int_list->num_nodes == 1);
    assert(*(int*)int_list->head->value == value);
    assert(int_list->head == int_list->tail);
    linked_list_destroy(int_list);
    
    linked_list_t* char_list = linked_list_create(sizeof(char));
    char c = 'A';
    linked_list_add(char_list, &c);
    assert(char_list->num_nodes == 1);
    assert(*(char*)char_list->head->value == c);
    linked_list_destroy(char_list);
    
    linked_list_t* struct_list = linked_list_create(sizeof(test_struct_t));
    test_struct_t test_struct = {1, "test"};
    linked_list_add(struct_list, &test_struct);
    assert(struct_list->num_nodes == 1);
    test_struct_t* result = (test_struct_t*)struct_list->head->value;
    assert(result->id == test_struct.id);
    assert(strcmp(result->name, test_struct.name) == 0);
    linked_list_destroy(struct_list);
}

// Test adding multiple values and verify list integrity
void test_multiple_adds() {
    linked_list_t* list = linked_list_create(sizeof(int));
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
    
    assert(list->tail != NULL);
    assert(*(int*)list->tail->value == values[4]);
    assert(list->tail->next == NULL);
    
    linked_list_destroy(list);
}

// Test boundary conditions for add_at operation
void test_add_at() {
    linked_list_t* list = linked_list_create(sizeof(int));
    int values[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    int start_value = 0;
    linked_list_add_at(list, &start_value, 0);
    assert(*(int*)list->head->value == 0);
    
    int mid_value = 100;
    linked_list_add_at(list, &mid_value, 3);
    
    int end_value = 200;
    linked_list_add_at(list, &end_value, list->num_nodes);
    assert(*(int*)list->tail->value == 200);
    
    int invalid_value = 999;
    linked_list_add_at(list, &invalid_value, list->num_nodes + 100);
    
    linked_list_destroy(list);
}

// Test edge cases for remove operations
void test_remove() {
    linked_list_t* list = linked_list_create(sizeof(int));
    
    linked_list_remove(list);
    assert(list->num_nodes == 0);
    
    int value = 42;
    linked_list_add(list, &value);
    linked_list_remove(list);
    assert(list->num_nodes == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    for (int i = 4; i >= 0; i--) {
        assert(*(int*)list->tail->value == values[i]);
        linked_list_remove(list);
        assert(list->num_nodes == i);
        
        if (i > 0) {
            assert(*(int*)list->tail->value == values[i - 1]);
        } else {
            assert(list->tail == NULL);
        }
    }
    
    linked_list_destroy(list);
}

// Test boundary conditions for remove_at operation
void test_remove_at() {
    linked_list_t* list = linked_list_create(sizeof(int));
    int values[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        linked_list_add(list, &values[i]);
    }
    
    linked_list_remove_at(list, 0);
    assert(list->num_nodes == 4);
    assert(*(int*)list->head->value == 2);
    
    linked_list_remove_at(list, list->num_nodes - 1);
    assert(list->num_nodes == 3);
    assert(*(int*)list->tail->value == 4);
    
    linked_list_remove_at(list, 1);
    assert(list->num_nodes == 2);
    
    linked_list_remove_at(list, 999);
    assert(list->num_nodes == 2);
    
    linked_list_destroy(list);
}

// Test list destruction with different states
void test_list_destruction() {
    // Test destroying empty list
    linked_list_t* empty_list = linked_list_create(sizeof(int));
    linked_list_destroy(empty_list);
    
    linked_list_destroy(NULL);
    
    linked_list_t* single_list = linked_list_create(sizeof(int));
    int value = 42;
    linked_list_add(single_list, &value);
    linked_list_destroy(single_list);
    
    linked_list_t* multi_list = linked_list_create(sizeof(int));
    for (int i = 0; i < 5; i++) {
        linked_list_add(multi_list, &i);
    }
    linked_list_destroy(multi_list);
}

int main() {
    // Run all tests
    test_linked_list_create();
    test_edge_cases_add();
    test_linked_list_add();
    test_multiple_adds();
    test_add_at();
    test_remove();
    test_remove_at();
    test_list_destruction();

    printf("[LINKED LIST] All tests completed successfully.\n");
    return 0;
}
