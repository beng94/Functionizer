CC = g++ -std=c++11
CFLAGS = -Wall -pedantic
OBJS = main.o node.o data.o entity.o entitycontainer.o test.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o OUT

debug:
	$(CC) -g $(CFLAGS) $(OBJS) -o OUT

%.o: %.cc
	$(CC) $(CFLAGS) $< -c

clean:
	#!/bin/bash
	./pictures/delete_pics.sh

pictures:
	#!/bin/bash
	./pictures/create_pics.sh

.PHONY: clean pictures
