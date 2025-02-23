#include <stdio.h>

#include "stack.h"

// Test the stack
int main() {
    // Create a stack of integers with a maximum of 10 elements
    stack_t* stack = stack_create(sizeof(int), 10);

    // Push 10 integers onto the stack
    for (int i = 0; i < 10; i++) {
        stack_push(stack, &i);
    }

    // Pop 10 integers from the stack
    for (int i = 0; i < 10; i++) {
        int* value = (int*)stack_pop(stack);

        if (value != NULL) {
            printf("%d\n", *value);
        }
    }

    // Destroy the stack
    stack_destroy(stack);

    // Create a stack of strings with a maximum of 4 elements
    stack_t* stack_str = stack_create(sizeof(char*), 4);

    // Push 4 strings onto the stack
    char* strings[] = {"AAA", "BBB", "CCC", "DDD"};
    for (int i = 0; i < 4; i++) {
        stack_push(stack_str, strings[i]);
    }

    // Pop 4 strings from the stack
    for (int i = 0; i < 4; i++) {
        char* value = (char*)stack_pop(stack_str);

        if (value != NULL) {
            printf("%s\n", value);
        }
    }

    // Destroy the stack
    stack_destroy(stack_str);

    return 0;
}
