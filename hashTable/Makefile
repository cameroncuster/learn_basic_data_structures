HEATMAP_SRC = src/heatMap.cpp src/application.cpp src/function.cpp

HASHTABLE_SRC = src/hashTable.cpp

MAIN_SRC = src/main.cpp

TEST_SRC = tests/testMain.cpp tests/testCases.cpp

HEATMAP_OBJS = $(HEATMAP_SRC:.cpp=.o)

HASHTABLE_OBJS = $(HASHTABLE_SRC:.cpp=.o)

MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

TEST_OBJ = $(TEST_SRC:.cpp=.o)

CXXFLAGS = -lstdc++fs -Wall -O3 -I inc
LIBS = -lGL -lX11 -lpng -lstdc++fs -lpthread

#GNU C/C++ compiler
GCC = g++

#GNU C/C++ linker
LINK = g++

all: heatMap main test

heatMap: $(HEATMAP_OBJS) $(HASHTABLE_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

main: $(MAIN_OBJ) $(HASHTABLE_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

test: $(TEST_OBJ) $(HASHTABLE_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf src/*.o src/*.d tests/*.o tests/*.d core heatMap main test

tar:
	tar cvf HashTable.tar $(HEATMAP_SRC) $(HASHTABLE_SRC) $(MAIN_SRC) Makefile inc/*.h

debug: CXXFLAGS = -DDEBUG -g -Wall -I inc
debug: main

help:
	@echo " make heatMap    - build the heatMap visualization"
	@echo " make main       - build the simple main executable"
	@echo " make clean      - remove .o .d core main heatMap test"
	@echo " make test       - build the test suite"
	@echo " make tar        - bundle everything up into a tarball"
	@echo " make help       - this message"

-include $(HEATMAP_SRC HASHTABLE_SRC MAIN_SRC:.cpp=.d)

%.d: %.cpp
	@set -e ; rm -rf $@; $(GCC) -MM $< $(CXXFLAGS) > $@
