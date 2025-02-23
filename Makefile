CC=gcc
CFLAGS=-Wall

all: bin/stack bin/stack_test bin/queue bin/queue_test

bin/stack: stack/main.c stack/stack.h stack/stack.c
	@mkdir -p bin
	$(CC) $(CFLAGS) stack/main.c stack/stack.c -o bin/stack

bin/stack_test: stack/stack_test.c stack/stack.h stack/stack.c
	@mkdir -p bin
	$(CC) $(CFLAGS) stack/stack_test.c stack/stack.c -o bin/stack_test

bin/queue: queue/main.c queue/queue.h queue/queue.c
	@mkdir -p bin
	$(CC) $(CFLAGS) queue/main.c queue/queue.c -o bin/queue

bin/queue_test: queue/queue_test.c queue/queue.h queue/queue.c
	@mkdir -p bin
	$(CC) $(CFLAGS) queue/queue_test.c queue/queue.c -o bin/queue_test

clean:
	@rm -rf bin
