#include <assert.h>
#include <stdio.h>

#include "deque.h"

// Test the deque_create function
void test_deque_create() {
    deque_t* deque = deque_create(sizeof(int), 10);
    assert(deque != NULL);
    assert(deque->element_size == sizeof(int));
    assert(deque->deque_size == 10);
    assert(deque->elements == 0);
    deque_destroy(deque);
}

// Test push_front function
void test_push_front() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int value = 10;
    deque_push_front(deque, &value);
    assert(deque->elements == 1);
    assert(*(int*)deque_peek_front(deque) == value);
    deque_destroy(deque);
}

// Test push_back function
void test_push_back() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int value = 10;
    deque_push_back(deque, &value);
    assert(deque->elements == 1);
    assert(*(int*)deque_peek_back(deque) == value);
    deque_destroy(deque);
}

// Test pop_front function
void test_pop_front() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int value = 10;
    deque_push_front(deque, &value);
    int* popped_value = (int*)deque_pop_front(deque);
    assert(*popped_value == value);
    assert(deque->elements == 0);
    deque_destroy(deque);
}

// Test pop_back function
void test_pop_back() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int value = 10;
    deque_push_back(deque, &value);
    int* popped_value = (int*)deque_pop_back(deque);
    assert(*popped_value == value);
    assert(deque->elements == 0);
    deque_destroy(deque);
}

// Test peek_front function
void test_peek_front() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int value = 10;
    deque_push_front(deque, &value);
    assert(*(int*)deque_peek_front(deque) == value);
    assert(deque->elements == 1);
    deque_destroy(deque);
}

// Test peek_back function
void test_peek_back() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int value = 10;
    deque_push_back(deque, &value);
    assert(*(int*)deque_peek_back(deque) == value);
    assert(deque->elements == 1);
    deque_destroy(deque);
}

// Test pop operations on empty deque
void test_pop_empty() {
    deque_t* deque = deque_create(sizeof(int), 10);
    assert(deque_pop_front(deque) == NULL);
    assert(deque_pop_back(deque) == NULL);
    deque_destroy(deque);
}

// Test peek operations on empty deque
void test_peek_empty() {
    deque_t* deque = deque_create(sizeof(int), 10);
    assert(deque_peek_front(deque) == NULL);
    assert(deque_peek_back(deque) == NULL);
    deque_destroy(deque);
}

// Test deque growth
void test_deque_grow() {
    deque_t* deque = deque_create(sizeof(int), 10);
    for (int i = 0; i < 11; i++) {
        deque_push_back(deque, &i);
    }
    assert(deque->elements == 11);
    assert(deque->deque_size == 20);
    deque_destroy(deque);
}

// Test mixed operations
void test_mixed_operations() {
    deque_t* deque = deque_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    
    // Push alternately to front and back
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            deque_push_front(deque, &values[i]);
        } else {
            deque_push_back(deque, &values[i]);
        }
    }
    
    assert(deque->elements == 5);
    
    // Pop alternately from front and back
    for (int i = 0; i < 5; i++) {
        int* value;
        if (i % 2 == 0) {
            value = (int*)deque_pop_front(deque);
        } else {
            value = (int*)deque_pop_back(deque);
        }
        assert(value != NULL);
    }
    
    assert(deque->elements == 0);
    deque_destroy(deque);
}

// Test deque behavior
int main() {
    // Run tests
    test_deque_create();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_peek_front();
    test_peek_back();
    test_pop_empty();
    test_peek_empty();
    test_deque_grow();
    test_mixed_operations();

    printf("[DEQUE] Tests completed successfully.\n");

    return 0;
}
