SRC = main.cpp classes.cpp

OBJ = main.o classes.o

BIN = tabu

CFLAGS = -g -glldb -w -std=c++17 # -ferror-limit=100

FLAGS = -o

CC = clang++

all: main.cpp classes.cpp
	${CC} ${CFLAGS} ${SRC} ${FLAGS} ${BIN}
clean:
	rm -rf ${OBJ} ${BIN} *~
	clear
