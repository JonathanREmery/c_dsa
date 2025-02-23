CC=gcc
CFLAGS=-Wall

all: bin/stack tests/stack_test bin/queue tests/queue_test bin/deque tests/deque_test

build: bin/stack bin/queue bin/deque

test: tests/stack_test tests/queue_test tests/deque_test
	@./tests/stack_test
	@./tests/queue_test
	@./tests/deque_test

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