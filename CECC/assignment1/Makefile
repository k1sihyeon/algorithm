#####
CC = gcc
CFLAGS = -I. -Wall -Wextra -std=c11

SRCS = main.c transition.c
OBJS = $(patsubst %.c, build/%.o, $(SRCS))
TARGET = assignment1$(OUT)

BUILD_DIR = build

# OS 대응
OS := $(shell uname 2>/dev/null || echo Windows)

ifeq ($(OS), Windows)
    OUT = .exe
    RM = del /Q
    MKDIR = if not exist build mkdir $(BUILD_DIR)
else
    OUT = .out
    RM = rm -rf
    MKDIR = mkdir -p $(BUILD_DIR)
endif

#####
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

build/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(MKDIR)

clean:
	$(RM) $(BUILD_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)