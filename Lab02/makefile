CC = gcc
CFLAGS = -c
OBJECTS = isOdd.o isEven.o main.o

all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog

%.o: %.c
	$(CC) $(CFLAGS) $<


clean:
	rm -rf *.o
	rm -rf prog

