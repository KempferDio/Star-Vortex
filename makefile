TARGET = Star Vortex

SRC = src/*.cpp src/Core/*.cpp
DEBUG_FOLDER = $(CURDIR)/bin/debug
MAIN_FOLDER = $(CURDIR)

debug_compile :
	cd obj/debug
	g++ -c $(SRC) -O0

clean:
	cd obj
	del *.o