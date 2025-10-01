CC = gcc
CFLAGS = -Wall -Wextra -MMD -MP

SRC_DIR = src
BUILD_DIR = build
INC_DIR = include

SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.c=.o))
DEP = $(OBJ:.o=.d)

TARGET = build/language

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

-include $(DEP)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

