PROJ_DIR = $(shell pwd)
SRC_DIR = $(PROJ_DIR)/src
INC_DIR = $(PROJ_DIR)/include
OBJ_DIR = $(PROJ_DIR)/obj
BIN_DIR = $(PROJ_DIR)/bin
LIB_DIR = $(PROJ_DIR)/lib

CC = gcc
AR = ar
CFLAGS = -I$(INC_DIR)
LDFLAGS = -L$(LIB_DIR) -lmybasic

OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
APP_OBJ = $(OBJ_DIR)/myapp.o
LIB_NAME = libmybasic.a
TARGET = $(BIN_DIR)/myapp

.PHONY: all basic clean

# 실행 파일을 만들기 전에 반드시 라이브러리를 먼저 생성
all: basic $(TARGET)

# 정적 라이브러리 만들기
basic: $(LIB_DIR)/$(LIB_NAME)

$(LIB_DIR)/$(LIB_NAME): $(OBJS)
	$(AR) rv $@ $^

# 개별 오브젝트 파일 만들기
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

# 실행 파일 링크
$(TARGET): $(APP_OBJ) $(LIB_DIR)/$(LIB_NAME)
	$(CC) -o $@ $(APP_OBJ) $(LDFLAGS)

# 클린
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_DIR)/*.a
