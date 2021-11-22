SOURCE_DIR = src

INCLUDE_DIR = inc

TEST_DIR = test

SOURCE = $(SOURCE_DIR)/application.cpp \
         $(SOURCE_DIR)/main.cpp \
         $(SOURCE_DIR)/graph.cpp

SOURCE_TEST = $(TEST_DIR)/testMain.cpp \
			  $(TEST_DIR)/testCases.cpp \
			  $(SOURCE_DIR)/graph.cpp

OBJS = $(SOURCE:.cpp=.o)

TEST_OBJS = $(SOURCE_TEST:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -I $(INCLUDE_DIR)
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lX11 -lGL -lpng -lpthread -lstdc++fs

.PHONY: clean

# Targets include all, tests, clean, debug, tar

all : graph

graph: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

tests: $(TEST_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf $(SOURCE_DIR)/*.o $(SOURCE_DIR)/*.d core graph tests

debug: CXXFLAGS = -Wall -I $(INCLUDE_DIR) -DDEBUG -g -lX11 -lGL -lpng -lpthread -lstdc++fs
debug: graph

tar: clean
	tar zcvf graph.tgz $(SOURCE) $(SOURCE_TEST) $(INCLUDE_DIR)/*.h Makefile

help:
	@echo "	make graph - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make test  - builds the test suite"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

