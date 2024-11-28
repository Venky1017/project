CC = gcc
CXX = g++
CFLAGS = -O2 -Wall
LDFLAGS =

SRC_DIR = src
OBJS_C = $(SRC_DIR)/bloom_filter.o $(SRC_DIR)/ripemd160.o
OBJS_BSGS = $(SRC_DIR)/rmd_bsgs_bloom.o
OBJS_BSGSD = $(SRC_DIR)/bsgsd.o

TARGET_BSGS = rmd_bsgs_bloom
TARGET_BSGSD = bsgsd

all: $(TARGET_BSGS) $(TARGET_BSGSD)

$(TARGET_BSGS): $(OBJS_C) $(OBJS_BSGS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(TARGET_BSGSD): $(OBJS_C) $(SRC_DIR)/bsgsd.cpp
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET_BSGS) $(TARGET_BSGSD)

.PHONY: all clean
