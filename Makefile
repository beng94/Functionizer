CC = g++ -std=c++11
CFLAGS = -Wall
OBJS = main.o node.o data.o entity.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o OUT

debug:
	$(CC) -g $(CFLAGS) data.cc data.hpp node.cc node.hpp entity.cc entity.hpp test.cc test.hpp main.cc -o OUT

main.o : main.cc
	$(CC) $(DEBUG) $(CFLAGS) main.cc -c

node.o : node.cc node.hpp
	$(CC) $(DEBUG) $(CFLAGS) node.cc -c

data.o : data.cc data.hpp
	$(CC) $(DEBUG) $(CFLAGS) data.cc -c

entity.o : entity.cc entity.hpp
	$(CC) $(DEBUG) $(CFLAGS) entity.cc -c

clean:
	#!/bin/bash
	./pictures/delete_pics.sh

picture:
	#!/bin/bash
	./pictures/create_pics.sh

