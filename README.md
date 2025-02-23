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
- `queue_enqueue(queue, value)`: Enqueue a value into the queue
- `queue_dequeue(queue)`: Dequeue a value from the queue
- `queue_peek(queue)`: Peek at the front value of the queue
- `queue_destroy(queue)`: Destroy the queue

## Deque

The deque is a double-ended queue that supports both FIFO and LIFO operations. My implementation is a dynamic deque that grows as needed. As the deque is intialized or grows, the data is centered in the middle of the deque to better support bi-directional operations.

Functionality:

- `deque_create(element_size, deque_size)`: Create a new deque
- `deque_push_front(deque, value)`: Push a value onto the front of the deque
- `deque_push_back(deque, value)`: Push a value onto the back of the deque
- `deque_pop_front(deque)`: Pop a value from the front of the deque
- `deque_pop_back(deque)`: Pop a value from the back of the deque
- `deque_peek_front(deque)`: Peek at the front value of the deque
- `deque_peek_back(deque)`: Peek at the back value of the deque
- `deque_destroy(deque)`: Destroy the deque

## Linked List

The linked list is a linear data structure that stores a collection of elements in a sequential manner. Each node in the list contains a value and a pointer to the next node in the list.

Functionality:

- `linked_list_create(element_size, list_size)`: Create a new linked list
- `linked_list_add(list, value)`: Add a value to the linked list
- `linked_list_add_at(list, value, index)`: Add a value to the linked list at a specific index
- `linked_list_remove(list)`: Remove a value from the linked list
- `linked_list_remove_at(list, index)`: Remove a value from the linked list at a specific index
- `linked_list_destroy(list)`: Destroy the linked list

### Building binaries

```bash
make build
```

### Running tests

```bash
make test
```