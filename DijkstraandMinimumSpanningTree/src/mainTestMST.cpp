#include <iostream>
#include <cassert>
#include "primMST.h"
#include "kruskalMST.h"
#include "dijkstra.h"

using namespace std;

const double epsilon = 1e-9;

int main( )
{
   WeightedGraph *G = new WeightedGraph(cin);

   set<int> vertices = G->Vertices( );

   int s = *G->Vertices( ).begin( );
   Dijkstra d( G, s );

   for( int v : vertices )
	   if( !d.hasPath( v ) )
		   return 0;

   KruskalMST kruskalMST(G);

   std::set<int>::iterator it = G->Vertices().begin();
   PrimMST primMST(G, *it);

   assert( kruskalMST.Weight( ) - primMST.Weight( ) < epsilon );
   delete G;
   return 0;
}
