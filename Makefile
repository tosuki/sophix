all: build
SRCS: main.c cursor.c

build:
	gcc sophix.c cursor.c keyboard.c wm.c error.c -o sophix -Wall -Wextra -lX11
