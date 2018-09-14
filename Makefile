.PHONY : all clean run
CFLAGS+= -Wall -std=c++11 -g
CC=g++
SRCS=main.cpp
BIN=tp1
INSTANCIAS= $(ls instancias)
INSTANCIASPYTHON = $(make $(ls instanciaspython)

all: clean tp1

$(BIN): $(SRCS)
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -rf $(BIN) *.o $(BIN)* experimentacion/*.out *.out

run: all
	clear
	./$(BIN)

instancia%: all
	cat instanciaspython/$@ | ./$(BIN) fb >> experimentacion/salidaFB.out


experimentos: all
	$(INSTANCIASPYTHON)

	