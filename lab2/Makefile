CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = uniq
OBJS = uniq.o
all : $(MAIN)

$(MAIN) : $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

uniq.o : uniq.c
	$(CC) $(CFLAGS) -c uniq.c

clean :
	rm *.o $(MAIN) core
