CC=g++
FLAGS=-Wall -Wextra
CPPVERSION=17
EXEC=exec.bin

FILES=main.cpp Matrix.cpp

all: clear compil run

compil:
	$(CC) -std=c++$(CPPVERSION) $(FLAGS) $(FILES) -o binaries/release/$(EXEC)

debug:
	$(CC) -g -std=c++$(CPPVERSION) $(FILES) -o binaries/release/$(EXEC)

run:
	./binaries/release/$(EXEC)

clean:
	rm -rf ./binaries/release/$(EXEC)
