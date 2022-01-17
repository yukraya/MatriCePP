CC=g++
FLAGS=-Wall -Wextra
CPPVERSION=17
EXEC=exec.bin

FILES=main.cpp Matrix.cpp

all: compil run

compil:
	$(CC) -std=c++$(CPPVERSION) $(FLAGS) -O2 $(FILES) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -rf ./$(EXEC)
