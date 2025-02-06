# Compiler
cc = gcc
TARGET=hashmap
SRCS = <source files>
OBJS=$(SRCS:.c=.o)

all:$(TARGET)

# link the .o files
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# compile the source code 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not real files)
.PHONY: all clean

