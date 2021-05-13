#
# makefile for binary search tree
#
# 'make test-int-bst' makes the executable 
# (so does 'make main')
#
# 'make OPT=<opt> test-int-bst makes the executable
#   with a non-default optimization level <opt> 
#   (possible values are -g, -O0, etc.)
# 'make clean' deletes object files
# 'make xclean' deletes object files and executable
#
# to use valgrind to check for memory leaks and other malloc/free errors:
# 'make OPT="-g -O0" test-int-bst
# 'valgrind test-int-bst'
#

OPT = -O
CFLAGS = -Wall -pedantic -std=c99 $(OPT)

EXE = test-int-bst
OBJS = test-int-bst.o test-helper.o int-bst.o

main: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

test-int-bst.o: test-int-bst.c int-bst.h

test-helper.o: test-helper.c test-helper.h

int-bst.o: int-bst.c int-bst.h

.PHONY: clean
clean:
	-rm $(OBJS)

.PHONY: xclean
xclean:
	-rm $(OBJS) $(EXE)