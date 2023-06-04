all:
		gcc -c -Wall -Werror -fpic sort.c -o sort.o
		gcc -shared -o libsort.so sort.o

clean:
	rm -f sort.o libsort.so
