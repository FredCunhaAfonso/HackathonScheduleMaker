CC := gcc
CFLAGS := -std=c11 -Wall -Wextra `pkg-config --cflags gtk+-3.0`
LDFLAGS := 
LIBS := -lm `pkg-config --libs gtk+-3.0`

SRC_DIR := src
BUILD_DIR := build
TARGET := studycat

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)