all: forth.out

forth.out: forth.o libstack.a
	gcc -o $@ $< -L. -lstack

forth.o: forth.c
	gcc -c $?

libstack.a: stack.o
	ar rcs $@ $?

stack.o: stack.c
	gcc -o $@ -c $?

clean:
	rm -fv *.a
	rm -fv *.o
	rm -fv *.out