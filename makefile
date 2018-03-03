CC = g++
SRC = src
HEADER = include
TARGET = Star-Vortex
LIB = lib
OBJ = obj
DEBUG = bin/debug
#RELEASE

SOURCES = $(wildcard $(SRC)/*.cpp) \
	 $(wildcard $(SRC)/Core/*.cpp) \
	 $(wildcard $(SRC)/Core/*.c) \
	 $(wildcard $(SRC)/*.c)

OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES)) 

CFLAGS = -c -Wall
LFLAGS = -L$(LIB) -lglfw3 -lopengl32 -lgdi32 -g -D DEBUG

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) -I$(HEADER) $^ -o $(DEBUG)/$(TARGET)

$(OBJ): $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/Core/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

$(OBJ)/%.o: $(SRC)/Core/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER) $< -o $@

clean:
	del /S *.o


.PHONY: all clean 