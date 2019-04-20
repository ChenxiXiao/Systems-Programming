CC = gcc
#define compile-time flags 
CFLAGS = -Wall -ansi -pedantic
#define any directories containing header files other than /usr/include
INCLUDE = 
MAIN = example
OBJS = example.o
TEST = test.c
all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

example.o : example.c
	$(CC) $(CFLAGS) -c example.c

test : $(TEST)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(TEST) -lm
	echo 
clean :
	rm *.o $(MAIN) core*
	echo "clean"

#depend : $(MAIN)
	#makedepend $(INCLUDES) $^
#automatically generates dependencies (added to end of makefile)