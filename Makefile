.PHONY : all clean run
CFLAGS+= -Wall -std=c++11
CC=g++
SRCS=main.cpp
BIN=tp1

all: clean tp1

$(BIN): $(SRCS)
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -rf $(BIN) *.o $(BIN)*

run: all
	clear
	./$(BIN)

instancia%: all
	clear
	cat instancias/$@.txt | ./$(BIN)
