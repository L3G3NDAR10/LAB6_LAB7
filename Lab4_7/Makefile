CC = gcc
CFLAGS = -Wall -Wextra

INPUT_SRC = input.c
CONVERT_SRC = convert.c
DATETIME_SRC = datetime.c
LOG_SRC = log.c
MAIN_SRC = main.c

all: main

main: main.o libinput libconvert libdatetime liblog
	$(CC) $(CFLAGS) -o $@ $< -L. -linput -lconvert -ldatetime -llog

libinput: input.o
	ar rcs $@.a $<

libconvert: convert.o
	ar rcs $@.a $<

libdatetime: datetime.o
	ar rcs $@.a $<

liblog: log.o
	ar rcs $@.a $<

main.o: $(MAIN_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

input.o: $(INPUT_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

convert.o: $(CONVERT_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

datetime.o: $(DATETIME_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

log.o: $(LOG_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.a main