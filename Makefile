CC = gcc
CFLAGS = -g -Wall 

OBJS = main.o ui.o matrix.o


main:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o main
