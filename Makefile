all = main.c search.c stats.c search.h stats.h mystring.h
search-cli: main.o
	gcc main.o -o search-cli
main.o: $(all)
	gcc -std=c99 -c main.c

make clean:
