PROJ_DIR = $(shell pwd)/..
SRC_DIR = $(PROJ_DIR)/basic_ops/src
OBJ_DIR = $(PROJ_DIR)/basic_ops/obj
LIB_DIR = $(PROJ_DIR)/lib
INC_DIR = $(PROJ_DIR)/include

CC = gcc
AR = ar
CFLAGS = -I$(INC_DIR)

OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
LIB_NAME = libmybasic.a

all: $(LIB_DIR)/$(LIB_NAME)

$(LIB_DIR)/$(LIB_NAME): $(OBJS)
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/$(LIB_NAME)
