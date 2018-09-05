.PHONY : all clean run
CFLAGS+= -Wall -std=c++11
CC=g++
SRCS=main.cpp
BIN=tp1
INSTANCIAS= instancia1 instancia2 instancia3

all: clean tp1

$(BIN): $(SRCS)
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -rf $(BIN) *.o $(BIN)* experimentacion/*.out *.out

run: all
	clear
	./$(BIN)

instancia%: all
	./$(BIN) instancias/$@.txt >> experimentacion/$@.out

experimentacion: $(INSTANCIAS)