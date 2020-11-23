CFLAGS = 
CC = gcc $(CFLAGS)

all: test_stack.out forth.out 

remake: clean all

debug: CFLAGS += -g
debug: all

forth.out: forth.o libstack.a
	$(CC) -o $@ $< -L. -lstack

forth.o: forth.c
	$(CC) -c $?

test_stack.out: test_stack.o libstack.a
	$(CC) -o $@ $< -L. -lstack

test_stack.o: test_stack.c
	$(CC) -c $?

libstack.a: stack.o
	ar rcs $@ $?

stack.o: stack.c
	$(CC) -o $@ -c $?

clean:
	rm -fv *.a
	rm -fv *.o
	rm -fv *.out