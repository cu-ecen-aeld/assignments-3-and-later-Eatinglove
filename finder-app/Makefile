CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 

ifeq ($(CROSS_COMPILE), aarch64-linux-gnu-)
    CC = $(CROSS_COMPILE)gcc
    CFLAGS += -mcpu=cortex-a57 -march=armv8-a
    LDFLAGS += --sysroot=/path/to/sysroot
endif

SRC = writer.c
OUT = writer

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)

clean:
	rm -f $(OUT) *.o

.PHONY: all clean

