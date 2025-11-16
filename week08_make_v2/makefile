.PHONY: all basic_ops advanced_ops clean

PROJ_DIR = $(shell pwd)
SRC_DIR = $(PROJ_DIR)/src
OBJ_DIR = $(PROJ_DIR)/obj
BIN_DIR = $(PROJ_DIR)/bin
LIB_DIR = $(PROJ_DIR)/lib
INC_DIR = $(PROJ_DIR)/include

CC = gcc
CFLAGS = -I$(INC_DIR)
LDFLAGS = -L$(LIB_DIR) -lmybasic -lmyadvanced -lm

TARGET = $(BIN_DIR)/myapp
APP_SRC = $(SRC_DIR)/myapp.c
APP_OBJ = $(OBJ_DIR)/myapp.o

STATIC_LIBS = $(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

all: basic_ops advanced_ops $(TARGET)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

$(TARGET): $(APP_OBJ) $(STATIC_LIBS)
	$(CC) -o $@ $(APP_OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
