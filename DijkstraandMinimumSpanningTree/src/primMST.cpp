#include "primMST.h"

using namespace std;

PrimMST::PrimMST( WeightedGraph *WG, int start )
{
    visit( WG, start );
    weight = 0.0;
    while( !minHeap.empty( ) )
    {
        Edge e = minHeap.top( );
        minHeap.pop( );
        int v = e.either( );
        int w = e.other( v );
        if( marked[v] && marked[w] )
            continue;
        mst.push_back( e );
        weight += e.Weight( );
        if( !marked[v] )
            visit( WG, v );
        if( !marked[w] )
            visit( WG, w );
    }
}

vector<Edge> PrimMST::Edges( )
{
    return mst;
}

double PrimMST::Weight( ) const
{
    return weight;
}

void PrimMST::visit( WeightedGraph *WG, int v )
{
    marked[v] = 1;
    for( Edge e : WG->adj( v ) )
        if( !marked[ e.other( v ) ] )
            minHeap.push( e );
}
