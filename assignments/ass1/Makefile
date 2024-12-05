CC=gcc
CFLAGS=-Wall -Werror
LDFLAGS=-lcunit -lm
OUTDIR = build
SRCS = main.c arr_ops.c
OBJS = $(SRCS:%.c=$(OUTDIR)/%.o)
TARGET = $(OUTDIR)/main

$(shell mkdir -p $(OUTDIR))

$(OUTDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(OUTDIR)