#include "dijkstra.h"

using namespace std;

// Undefined behavior if graph is nullptr or start node does not exist in the graph
Dijkstra::Dijkstra( WeightedGraph *WG, int s ) : start( s )
{
    for( int v : WG->Vertices( ) )
        dist[v] = numeric_limits<double>::infinity( );

    dist[start] = 0.0;
    pq.push( DijNode( start, 0 ) );
    while( !pq.empty( ) )
    {
        int v = pq.top( ).vertex;
        pq.pop( );
        known[v] = 1;
        for( Edge e : WG->adj( v ) )
            relax( v, e );
    }
}

double Dijkstra::distance( int v )
{
    return dist[v];
}

bool Dijkstra::hasPath( int v )
{
    return dist[v] != numeric_limits<double>::infinity( );
}

list<int> Dijkstra::pathTo( int v )
{
    list<int> path;
    if( !hasPath( v ) )
        return path;

    for( int x = v; x != start; x = prev[x] )
        path.push_front( x );

    path.push_front( start );
    return path;
}

void Dijkstra::relax( int v, Edge e )
{
    int w = e.other( v );
    if( dist[w] > dist[v] + e.Weight( ) )
    {
        dist[w] = dist[v] + e.Weight( );
        pq.push( DijNode( w, dist[w] ) );
        prev[w] = v;
    }
}
