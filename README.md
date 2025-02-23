# DSA in C

## Stack

The stack is a LIFO (Last In First Out) data structure. My implementation is a dynamic stack that grows as needed.

Functionality:

- `stack_create(element_size, stack_size)`: Create a new stack
- `stack_push(stack, value)`: Push a value onto the stack
- `stack_pop(stack)`: Pop a value from the stack
- `stack_peek(stack)`: Peek at the top value of the stack
- `stack_destroy(stack)`: Destroy the stack

## Queue

The queue is a FIFO (First In First Out) data structure. My implementation is a dynamic queue that grows as needed.

Functionality:

- `queue_create(element_size, queue_size)`: Create a new queue
- `enqueue(queue, value)`: Enqueue a value into the queue
- `dequeue(queue)`: Dequeue a value from the queue
- `queue_peek(queue)`: Peek at the front value of the queue
- `queue_destroy(queue)`: Destroy the queue