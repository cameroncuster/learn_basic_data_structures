/***************************************************************************//**
 * @file bfsPaths.cpp
 ******************************************************************************/
#include "bfsPaths.h"

using namespace std;

// It's your job to implement the BFSPaths functionality

/// Given a graph and a start node, construct the client object
BFSPaths::BFSPaths( Graph *G, int s ) : source( s )
{
	bfs( G, s );
}

/// Answers the question, is there a path from the start to vertex 'v'
bool BFSPaths::hasPath( int v )
{
	return marked[v];
}

/// Returns the path (from start node to v) of the path if it exists
list<int> BFSPaths::pathTo( int v )
{
	list<int> path;
	if( !marked[v] )
		return path;
	while( prev.count( v ) )
	{
		path.push_front( v );
		v = prev[v];
	}
	path.push_front( v );
	return path;
}

/// Return the distance from the source to vertex 'v'
int BFSPaths::distance( int v )
{
	return dist[v]; // returns -1 for invalid distances
}

map<int, bool> BFSPaths::Visited( )
{
	return marked;
}

/// Perform a breadth-first-search starting at node s
void BFSPaths::bfs( Graph *G, int s )
{
	queue<int> q;
	int v;

	q.push( s );
	marked[s] = 1;
	while( !q.empty( ) )
	{
		v = q.front( );
		q.pop( );
		for( int u : G->adj( v ) )
			if( !marked[u] )
			{
				marked[u] = 1;
				q.push( u );
				dist[u] = dist[v] + 1;
				prev[u] = v;
			}
	}
}
