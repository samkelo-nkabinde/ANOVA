CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

LDLIBS = -lm

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

TARGET = $(BIN_DIR)/anova

SRCS = main.c $(wildcard $(SRC_DIR)/*.c)

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)
