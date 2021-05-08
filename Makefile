CC =gcc
CFLAGS = -Wall -pedantic -std=c99 -O
LDLIBS = -lm

#This code is for game of life
#
# makefile for game of life programs
#
# 'make game-of-life' or 'make game-of-life-random' makes executables
#
# 'make clean' deletes object files
# 'make xclean' deletes object files and executables
#

# OPT = -O
# CFLAGS = -Wall -pedantic -std=c99 $(OPT)

# EXE1 = game-of-life
# EXE2 = game-of-life-random
# OBJS1 = game-of-life.o game-of-life-util.o
# OBJS2 = game-of-life-random.o game-of-life-util.o

# all: $(EXE1) $(EXE2)

# $(EXE1): $(OBJS1)
# 	$(CC) -o $(EXE1) $(OBJS1)

# $(EXE2): $(OBJS2)
# 	$(CC) -o $(EXE2) $(OBJS2)

# game-of-life.o: game-of-life.c game-of-life-util.h
# game-of-life-random.o: game-of-life-random.c game-of-life-util.h

# game-of-life-util.o: game-of-life-util.h game-of-life-util.c

# .PHONY: clean
# clean:
# 	-rm $(OBJS1) $(OBJS2)

# .PHONY: xclean
# xclean:
# 	-rm $(OBJS1) $(OBJS2) $(EXE1) $(EXE2)