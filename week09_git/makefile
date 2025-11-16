CC      = gcc
CFLAGS  = -fPIC -Iinclude
LDFLAGS = -Llib -lmyops

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

OPS_SRC = $(SRC_DIR)/myadd.c \
          $(SRC_DIR)/mysub.c \
          $(SRC_DIR)/mymul.c \
          $(SRC_DIR)/mydiv.c \
          $(SRC_DIR)/mymod.c \
          $(SRC_DIR)/mypow.c

OPS_OBJ = $(OBJ_DIR)/myadd.o \
          $(OBJ_DIR)/mysub.o \
          $(OBJ_DIR)/mymul.o \
          $(OBJ_DIR)/mydiv.o \
          $(OBJ_DIR)/mymod.o \
          $(OBJ_DIR)/mypow.o

APP_SRC = $(SRC_DIR)/myapp.c
APP_OBJ = $(OBJ_DIR)/myapp.o

SHARED_LIB = $(LIB_DIR)/libmyops.so.1.0
SONAME     = libmyops.so.1

all: $(BIN_DIR)/myapp

$(SHARED_LIB): $(OPS_OBJ)
	$(CC) -shared -Wl,-soname,$(SONAME) -o $@ $^

	ln -sf libmyops.so.1.0 lib/libmyops.so.1
	ln -sf libmyops.so.1 lib/libmyops.so

$(BIN_DIR)/myapp: $(APP_OBJ) $(SHARED_LIB)
	$(CC) -o $@ $(APP_OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(LIB_DIR)/*.so*
	rm -f $(BIN_DIR)/myapp

.PHONY: all clean
