#include "stack.h"

/**
 * Create a new stack
 * @param element_size Size of each element in the stack
 * @param stack_size Maximum number of elements in the stack
 * @return Pointer to the stack
 */
stack_t* stack_create(uint64_t element_size, uint64_t stack_size) {
    // Allocate memory for the stack structure
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));

    // Initialize the stack
    stack->element_size = element_size;
    stack->stack_size = stack_size;
    stack->elements = 0;
    stack->base = (void*)malloc(stack_size * element_size);
    stack->top = stack->base;

    // Return the stack
    return stack;
}

/**
 * Grow the stack
 * @param stack Pointer to the stack
 */
void stack_grow(stack_t* stack) {
    // Double the stack size
    stack->stack_size *= 2;

    // Reallocate the stack
    stack->base = realloc(stack->base, stack->stack_size * stack->element_size);
    stack->top = stack->base + stack->elements * stack->element_size;
}

/**
 * Push a value onto the stack
 * @param stack Pointer to the stack
 * @param value Value to push onto the stack
 */
void stack_push(stack_t* stack, void* value) {
    // If the stack is full, grow it
    if (stack->elements == stack->stack_size) {
        stack_grow(stack);
    }

    // Copy the value to the top of the stack
    memcpy(stack->top, value, stack->element_size);
    stack->top += stack->element_size;
    stack->elements++;
}

/**
 * Pop a value from the stack
 * @param stack Pointer to the stack
 * @return Pointer to the element, NULL if the stack is empty
 */
void* stack_pop(stack_t* stack) {
    // If the stack is empty, return NULL
    if (stack->top == stack->base) {
        return NULL;
    }

    // Pop the value from the stack
    stack->top -= stack->element_size;
    stack->elements--;

    // Return the value
    return stack->top;
}

/**
 * Peek at the top value of the stack
 * @param stack Pointer to the stack
 * @return Pointer to the element, NULL if the stack is empty
 */
void* stack_peek(stack_t* stack) {
    // If the stack is empty, return NULL
    if (stack->top == stack->base) {
        return NULL;
    }

    // Return the value
    return stack->top - stack->element_size;
}

/**
 * Destroy the stack
 */
void stack_destroy(stack_t* stack) {
    // Free the memory allocated for the stack
    free(stack->base);
    free(stack);
}