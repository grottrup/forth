COMPILER = gcc

default: test clean

debug: COMPILER += -g # add debug flag
debug: compile

test: 
	make test_stack.out 
	make test_dictionary.out

test_dictionary.out:
	$(COMPILER) -c stack.c
	$(COMPILER) -c dictionary.c
	$(COMPILER) -c operations.c
	ar rcs libdictionary.a dictionary.o operations.o stack.o
	$(COMPILER) -c test_dictionary.c
	$(COMPILER) test_dictionary.o -ldictionary -L . -o test_dictionary.out
	./test_dictionary.out

test_stack.out:
	$(COMPILER) -c stack.c
	ar rcs libstack.a stack.o
	$(COMPILER) -c test_stack.c
	$(COMPILER) test_stack.o -lstack -L . -o test_stack.out
	./test_stack.out

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.out