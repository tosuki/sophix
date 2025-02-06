all: build
SRCS: main.c cursor.c

build:
	gcc main.c cursor.c keyboard.c wm.c error.c -o main -Wall -Wextra -lX11
