CC = gcc
CFLAGS = -Wall -Wextra -O3

LDFLAGS = -L/opt/shares/openfoam/software/OpenBLAS/0.3.23-GCC-12.3.0/lib
LDLIBS = -lopenblas

TARGET = OpenBLAS_GEMM.elf
SRCS = OpenBLAS_GEMM.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean all
