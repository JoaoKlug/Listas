CC = g++
BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj
HEADER_DIR = include

CPPFLAGS = -g -Wall -I$(HEADER_DIR)

BIN = $(BIN_DIR)/main
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(BIN_DIR) $(OBJ_DIR)

.PHONY: all clean build