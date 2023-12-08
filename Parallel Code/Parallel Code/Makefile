# To make the code, run "make par" to make the parallel version
# Type "make clean" if you want to clean up before
# finally ./par to run it

CC = gcc
CFLAGS = -g -Wall

DEPS =	vars_defs_functions.h timer.h

OBJ = 	parallel.o\
	basicThread.o\
	countBurningNeighbours_ClosedBoundaries.o\
	decide_F_to_B.o\
	decide_B_to_X_VaryingDays.o

	




%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

par: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean: $(OBJ)
	rm *.o
	rm par
