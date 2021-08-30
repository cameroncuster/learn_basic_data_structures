#include "kruskalMST.h"

using namespace std;

KruskalMST::KruskalMST( WeightedGraph *WG )
{
    priority_queue<Edge, vector<Edge>, CompareEdge> minHeap;
    for( Edge e : WG->Edges( ) )
        minHeap.push( e );

    DisjointSet ds;
    for( int v : WG->Vertices( ) )
        ds.makeSet( v );

    weight = 0.0;
    while( !minHeap.empty( ) && mst.size( ) < unsigned ( WG->V( ) - 1 ) )
    {
        Edge e = minHeap.top( );
        minHeap.pop( );
        int v = e.either( );
        int w = e.other( v );
        if( ds.Find( v ) != ds.Find( w ) )
        {
            ds.Union( v, w );
            mst.push_back( e );
            weight += e.Weight( );
        }
    }
}

vector<Edge> KruskalMST::Edges( )
{
    return mst;
}

double KruskalMST::Weight( ) const
{
    return weight;
}
