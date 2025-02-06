all: build

build:
	gcc main.c -o main -Wall -Wextra -lX11
