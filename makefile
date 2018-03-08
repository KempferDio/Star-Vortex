CC = g++
SRC = src
HEADER = include -Iusr/local/include
TARGET = Star-Vortex
LIB = /usr/lib
OBJ = obj
DEBUG = bin/debug
#RELEASE

SOURCES = $(wildcard $(SRC)/*.cpp) \
	 $(wildcard $(SRC)/Core/*.cpp) \
	 $(wildcard $(SRC)/Core/*.c) \
	 $(wildcard $(SRC)/*.c)

OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES)) 

CFLAGS = -c -Wall -DDEBUG 
LFLAGS = -L$(LIB) -lglfw -lGL -g -ldl 

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC)  -I$(HEADER) $^ $(LFLAGS) -o $(DEBUG)/$(TARGET)

$(OBJ): $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/Core/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/Core/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/Core/Game/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/Core/Game/%.c
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

clear:
	find . -name "*.o" -type f -delete


.PHONY: all clean 