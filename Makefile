all: build
SRCS: main.c cursor.c

build:
	gcc main.c cursor.c -o main -Wall -Wextra -lX11
