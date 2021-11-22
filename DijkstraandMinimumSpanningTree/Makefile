SOURCE_DIR = src

INCLUDE_DIR = inc

SOURCE = $(SOURCE_DIR)/application.cpp \
         $(SOURCE_DIR)/main.cpp \
         $(SOURCE_DIR)/weightedGraph.cpp \
         $(SOURCE_DIR)/edge.cpp \
         $(SOURCE_DIR)/dijkstra.cpp \
         $(SOURCE_DIR)/kruskalMST.cpp \
         $(SOURCE_DIR)/disjointSet.cpp \
         $(SOURCE_DIR)/primMST.cpp

GENERATE_GRAPH_SOURCE = $(SOURCE_DIR)/generateGraph.cpp \
						$(SOURCE_DIR)/edge.cpp

OBJS = $(SOURCE:.cpp=.o)

GENERATE_GRAPH_OBJS = $(GENERATE_GRAPH_SOURCE:.cpp=.o)

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

all : application generateGraph

application: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

generateGraph: $(GENERATE_GRAPH_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.dat $(SOURCE_DIR)/*.o $(SOURCE_DIR)/*.d core application generateGraph

debug: CXXFLAGS = -Wall -I $(INCLUDE_DIR) -DDEBUG -g -lX11 -lGL -lpng -lpthread -lstdc++fs
debug: application

tar: clean
	tar zcvf application.tgz $(SOURCE) $(GENERATE_GRAPH_SOURCE) $(INCLUDE_DIR)/*.h Makefile

help:
	@echo "	make application  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

