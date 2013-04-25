all:
	gcc -o tree.o -c tree.c -I linked-list
	ar rv tree.a tree.o
