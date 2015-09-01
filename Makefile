CC = g++
CFLAGS = -Wall
DEBUG = -g
OBJS = main.o node.o data.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o OUT

main.o : main.cc
	$(CC) $(CFLAGS) main.cc -c

node.o : node.cc node.hpp
	$(CC) $(CFLAGS) node.cc -c

data.o : data.cc data.hpp
	$(CC) $(CFLAGS) data.cc -c


