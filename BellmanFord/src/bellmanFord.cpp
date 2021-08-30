/********************************************************************//**
 * @file
 ***********************************************************************/
#include "bellmanFord.h"

using namespace std;

BellmanFord::BellmanFord( WeightedGraph *G, int s ) : start( s )
{
    for( int v : G->Vertices( ) )
        dist[v] = numeric_limits<double>::infinity( );

    dist[start] = 0;
    for( int i = 0;  i < G->V( ) - 1; i++ )
        for( Edge e : G->Edges( ) )
            relax( e );

    // if able to relax negative weight cycle exists in the graph ( assign -INF )
    for( int i = 0;  i < G->V( ) - 1; i++ )
        for( Edge e : G->Edges( ) )
            if( dist[ e.either( ) ] + e.Weight( ) < dist[ e.other( e.either( ) ) ] )
                dist[ e.other( e.either( ) ) ] = -numeric_limits<double>::infinity( );
}

bool BellmanFord::hasPath( int v )
{
    return dist[v] != numeric_limits<double>::infinity( );
}

list<int> BellmanFord::pathTo( int v )
{
    list<int> path;
    if( !hasPath( v ) )
        return path;

    for( int x = v; x != start; x = prev[x] )
        path.push_front( x );

    path.push_front( start );
    return path;
}

double BellmanFord::distance( int v )
{
    return dist[v];
}

void BellmanFord::relax( Edge e )
{
    if( dist[ e.either( ) ] + e.Weight( ) < dist[ e.other( e.either( ) ) ] )
        dist[ e.other( e.either( ) ) ] = dist[ e.either( ) ] + e.Weight( );
}
