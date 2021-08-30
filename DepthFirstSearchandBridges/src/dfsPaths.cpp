#include "dfsPaths.h"

using namespace std;

DFSPaths::DFSPaths( Graph *G, int s ) : source( s )
{
	dfs( G, s );
}

void DFSPaths::dfs( Graph *G, int s )
{
	marked[s] = 1;
	for( int u : G->adj( s ) )
		if( !marked[u] )
		{
			prev[u] = s;
			dfs( G, u );
		}
}

bool DFSPaths::hasPathTo( int v  )
{
	return marked[v];
}

list<int> DFSPaths::pathTo( int v )
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
