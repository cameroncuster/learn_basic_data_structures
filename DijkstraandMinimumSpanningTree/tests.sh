#!/bin/bash
diff=`expr $4 - $3`
GREEN='\033[0;32m'
NC='\033[0m'
make -s generateGraph
g++ -Wall -O3 -I inc -o mainTest src/mainTestMST.cpp src/primMST.cpp src/kruskalMST.cpp src/weightedGraph.cpp src/edge.cpp src/disjointSet.cpp src/dijkstra.cpp
for (( i = $1; i < $2; i++ ))
do
	for (( j = $3; j < $4; j++ ))
	do
		./generateGraph $j $i > wgraph.dat
		./mainTest < wgraph.dat
	done
	printf "VERTICES $diff - DEGREE $i - ${GREEN}SUCCESS${NC}\n"
done
make -s clean
rm mainTest
