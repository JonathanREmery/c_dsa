#include <assert.h>
#include <stdio.h>

#include "stack.h"

// Test the stack_create function
void test_stack_create() {
    stack_t* stack = stack_create(sizeof(int), 10);
    assert(stack != NULL);
    assert(stack->element_size == sizeof(int));
    assert(stack->stack_size == 10);
    assert(stack->elements == 0);
    assert(stack->base != NULL);
    assert(stack->top == stack->base);
    stack_destroy(stack);
}

// Test the stack_push function
void test_stack_push() {
    stack_t* stack = stack_create(sizeof(int), 10);
    int value = 10;
    stack_push(stack, &value);
    assert(stack->elements == 1);
    assert(*(int*)(stack->top - sizeof(int)) == value);
    assert(stack->top == stack->base + sizeof(int));
    stack_destroy(stack);
}

// Test the stack_pop function
void test_stack_pop() {
    stack_t* stack = stack_create(sizeof(int), 10);
    int value = 10;
    stack_push(stack, &value);
    int* popped_value = (int*)stack_pop(stack);
    assert(*popped_value == value);
    assert(stack->elements == 0);
    assert(stack->top == stack->base);
    stack_destroy(stack);
}

// Test the stack_peek function
void test_stack_peek() {
    stack_t* stack = stack_create(sizeof(int), 10);
    int value = 10;
    stack_push(stack, &value);
    int* peeked_value = (int*)stack_peek(stack);
    assert(*peeked_value == value);
    assert(*(int*)(stack->top - sizeof(int)) == value);
    assert(stack->elements == 1);  // Peek shouldn't change stack state
    assert(stack->top == stack->base + sizeof(int));
    stack_destroy(stack);
}

// Test the stack_destroy function
void test_stack_destroy() {
    stack_t* stack = stack_create(sizeof(int), 10);
    stack_destroy(stack);
}

// Test stack_pop behavior when the stack is empty
void test_stack_pop_empty() {
    stack_t* stack = stack_create(sizeof(int), 10);
    void* value = stack_pop(stack);
    assert(value == NULL);
    assert(stack->elements == 0);
    assert(stack->top == stack->base);
    stack_destroy(stack);
}

// Test stack_peek behavior when the stack is empty
void test_stack_peek_empty() {
    stack_t* stack = stack_create(sizeof(int), 10);
    void* value = stack_peek(stack);
    assert(value == NULL);
    assert(stack->elements == 0);
    assert(stack->top == stack->base);
    stack_destroy(stack);
}

// Test stack growth behavior
void test_stack_grow() {
    stack_t* stack = stack_create(sizeof(int), 10);
    for (int i = 0; i < 11; i++) {
        stack_push(stack, &i);
    }
    assert(stack->elements == 11);
    assert(stack->stack_size == 20);
    assert(stack->top == stack->base + (11 * sizeof(int)));
    stack_destroy(stack);
}

// Test LIFO behavior with multiple push/pop operations
void test_stack_lifo() {
    stack_t* stack = stack_create(sizeof(int), 10);
    int values[] = {1, 2, 3, 4, 5};
    
    // Push all values
    for (int i = 0; i < 5; i++) {
        stack_push(stack, &values[i]);
    }
    
    // Pop and verify LIFO order (last in, first out)
    for (int i = 4; i >= 0; i--) {
        int* popped = (int*)stack_pop(stack);
        assert(*popped == values[i]);
    }
    
    assert(stack->elements == 0);
    assert(stack->top == stack->base);
    stack_destroy(stack);
}

// Test stack behavior
int main() {
    // Run tests
    test_stack_create();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();
    test_stack_destroy();
    test_stack_pop_empty();
    test_stack_peek_empty();
    test_stack_grow();
    test_stack_lifo();

    printf("[STACK] Tests completed successfully.\n");

    return 0;
}