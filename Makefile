SRCMODULES =\
	redevastation.cpp \
	LvlGenBSP.cpp\
	LvlMap.cpp \
	Engine.cpp \
	Level.cpp\
	Creature.cpp\
	Material.cpp
OBJMODULES=$(SRCMODULES:.cpp=.o)

.PHONY: clean

TARGET=redevastation
CXX=x86_64-w64-mingw32-g++

linux: CXX=g++
linux: CXXFLAGS=-g `pkg-config --cflags ncurses` -DLINUX
linux: LDFLAGS=`pkg-config --libs ncurses`

all: ${TARGET}.exe

linux: ${OBJMODULES}
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c CursedInterface.cpp
	${CXX} -o ${TARGET} CursedInterface.o $^ ${LDFLAGS}

${TARGET}.exe: ${OBJMODULES}
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c TXLibInterface.cpp
	${CXX} -o ${TARGET}.exe TXLibInterface.o $^

%.o: %.cpp %.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

run: ${TARGET}.exe
	WINEPREFIX=~/.wine64 wine64-development ${TARGET}.exe

clean:
	rm *.o *~ *.exe
