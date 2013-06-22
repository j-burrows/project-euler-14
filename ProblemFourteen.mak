#ProblemFourteen.mak
CC = gcc
WARNINGS = -Wall

all: ProblemFourteen.exe

ProblemFourteen.exe: inputs.o ProblemFourteen.o
	$(CC) $(WARNINGS) inputs.o ProblemFourteen.o -o ProblemFourteen.exe

inputs.o: inputs.c inputs.h
	$(CC) -c inputs.c

ProblemFourteen.o: ProblemFourteen.c ProblemFourteen.h
	$(CC) -c ProblemFourteen.c
	
clean:
	rm -rf *o ProblemFourteen.exe
