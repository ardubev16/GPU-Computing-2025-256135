CC = gcc
CFLAGS = -Wall -Wextra -O3

TARGET = hi_from_host.elf
SRCS = hi_from_host.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean all
