.PHONY : all clean run
CFLAGS+= -Wall -std=c++11
CC=g++
SRCS=main.cpp
BIN=tp1
INSTANCIAS= $(ls instancias)

all: clean tp1

$(BIN): $(SRCS)
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -rf $(BIN) *.o $(BIN)* experimentacion/*.out *.out

run: all
	clear
	./$(BIN)

instancia%:
	./$(BIN) instancias/$@ >> experimentacion/$@.out

experimentos: all
	

	