COMPILER = gcc

all: test.out

manual: all
	./test.out test

auto: all
	./test.out

debug: COMPILER += -g # add debug flag
debug: all

test.out: test.c libraries.a
	$(COMPILER) -o $@ $< -L -l libraries.a

libraries.a: stack.o operations.o parser.o dict.o sentence.o
	ar rcs $@ $?

dict.o: dict.c
	$(COMPILER) -c $?

parser.o: parser.c
	$(COMPILER) -c $?

operations.o: operations.c
	$(COMPILER) -c $?

stack.o: stack.c
	$(COMPILER) -c $?

sentence.o: sentence.c
	$(COMPILER) -c $?

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.out