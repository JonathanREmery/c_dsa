#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * Stack structure
 */
typedef struct {
    uint64_t element_size; // Size of each element in the stack
    uint64_t stack_size;   // Maximum number of elements in the stack
    uint64_t elements;     // Number of elements in the stack
    void*    base;         // Pointer to the base of the stack
    void*    top;          // Pointer to the top of the stack
} stack_t;

/**
 * Create a new stack
 * @param element_size Size of each element in the stack
 * @param stack_size Maximum number of elements in the stack
 * @return Pointer to the stack
 */
stack_t* stack_create(uint64_t element_size, uint64_t stack_size);

/**
 * Grow the stack
 * @param stack Pointer to the stack
 */
void stack_grow(stack_t* stack);

/**
 * Push a value onto the stack
 * @param stack Pointer to the stack
 * @param value Value to push onto the stack
 */
void stack_push(stack_t* stack, void* value);

/**
 * Pop a value from the stack
 * @param stack Pointer to the stack
 * @return Pointer to the element, NULL if the stack is empty
 */
void* stack_pop(stack_t* stack);

/**
 * Peek at the top value of the stack
 * @param stack Pointer to the stack
 * @return Pointer to the element, NULL if the stack is empty
 */
void* stack_peek(stack_t* stack);

/**
 * Destroy the stack
 */
void stack_destroy(stack_t* stack);

#endif