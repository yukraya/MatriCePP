CC=g++
FLAGS=-Wall -Wextra
CPPVERSION=17
EXEC=exec.bin

FILES=main.cpp Matrix.cpp

all: clear compil run

compil: clear
	$(CC) -std=c++$(CPPVERSION) $(FLAGS) -O2 $(FILES) -o binaries/release/$(EXEC)

run: clear
	./binaries/release/$(EXEC)

clean: clear
	rm -rf ./binaries/release/$(EXEC)

clear: clear
	clear