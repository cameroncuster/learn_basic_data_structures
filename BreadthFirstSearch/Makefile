SOURCE_DIR = src

INCLUDE_DIR = inc

SOURCE = $(SOURCE_DIR)/application.cpp \
         $(SOURCE_DIR)/disjoint.cpp \
         $(SOURCE_DIR)/main.cpp \
         $(SOURCE_DIR)/maze.cpp \
         $(SOURCE_DIR)/graph.cpp \
         $(SOURCE_DIR)/bfsPaths.cpp

OBJS = $(SOURCE:.cpp=.o)

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

# Targets include all, clean, debug, tar

all : maze

maze: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf $(SOURCE_DIR)/*.o $(SOURCE_DIR)/*.d core maze

debug: CXXFLAGS = -Wall -I $(INCLUDE_DIR) -DDEBUG -g -lX11 -lGL -lpng -lpthread -lstdc++fs
debug: maze

tar: clean
	tar zcvf maze.tgz $(SOURCE) $(INCLUDE_DIR)/*.h Makefile

help:
	@echo "	make maze  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

