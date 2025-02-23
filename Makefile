CC=gcc
CFLAGS=-Wall

all: bin/stack tests/stack_test bin/queue tests/queue_test bin/deque tests/deque_test bin/linked_list tests/linked_list_test

build: bin/stack bin/queue bin/deque bin/linked_list

test: tests/stack_test tests/queue_test tests/deque_test tests/linked_list_test
	@./tests/stack_test
	@./tests/queue_test
	@./tests/deque_test
	@./tests/linked_list_test

clean:
	@rm -rf bin
	@rm -rf tests

bin/stack: stack/main.c stack/stack.h stack/stack.c
	@mkdir -p bin
	$(CC) $(CFLAGS) stack/main.c stack/stack.c -o bin/stack

tests/stack_test: stack/stack_test.c stack/stack.h stack/stack.c
	@mkdir -p tests
	$(CC) $(CFLAGS) stack/stack_test.c stack/stack.c -o tests/stack_test

bin/queue: queue/main.c queue/queue.h queue/queue.c
	@mkdir -p bin
	$(CC) $(CFLAGS) queue/main.c queue/queue.c -o bin/queue

tests/queue_test: queue/queue_test.c queue/queue.h queue/queue.c
	@mkdir -p tests
	$(CC) $(CFLAGS) queue/queue_test.c queue/queue.c -o tests/queue_test

bin/deque: deque/main.c deque/deque.h deque/deque.c
	@mkdir -p bin
	$(CC) $(CFLAGS) deque/main.c deque/deque.c -o bin/deque

tests/deque_test: deque/deque_test.c deque/deque.h deque/deque.c
	@mkdir -p tests
	$(CC) $(CFLAGS) deque/deque_test.c deque/deque.c -o tests/deque_test

bin/linked_list: linked_list/main.c linked_list/linked_list.h linked_list/linked_list.c
	@mkdir -p bin
	$(CC) $(CFLAGS) linked_list/main.c linked_list/linked_list.c -o bin/linked_list

tests/linked_list_test: linked_list/linked_list_test.c linked_list/linked_list.h linked_list/linked_list.c
	@mkdir -p tests
	$(CC) $(CFLAGS) linked_list/linked_list_test.c linked_list/linked_list.c -o tests/linked_list_test