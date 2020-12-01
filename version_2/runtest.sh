# Update library
gcc -g -c stack.c
ar rcs libstack.a stack.o

# Run tests for library
gcc -c test_stack.c
gcc test_stack.o -lstack -L . -o test_stack
./test_stack