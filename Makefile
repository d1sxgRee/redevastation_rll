SRCMODULES = redevastation.cpp LvlGenBSP.cpp LvlMap.cpp
OBJMODULES = $(SRCMODULES:.cpp=.o)
.PHONY: clean

TARGET=redevastation
CXX=x86_64-w64-mingw32-g++

linux: CXX=g++
linux: CXXFLAGS=-g

all: ${TARGET}.exe

linux: ${OBJMODULES}
	${CXX} -o ${TARGET} $^

${TARGET}.exe: ${OBJMODULES}
	${CXX} -o ${TARGET}.exe $^

%.o: %.cpp %.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

run: ${TARGET}.exe
	WINEPREFIX=~/.wine64 wine64-development ${TARGET}.exe

clean:
	rm *.o *~ *.exe
