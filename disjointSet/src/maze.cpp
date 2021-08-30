#include "maze.h"
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

Maze::Maze( int w, int h ) : d( w * h )
{
	int i;
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	edges.resize( ( w - 1 ) * h + ( h - 1 ) * w );
	currEdge = 0;
	for( i = 0; i < w * h; i++ )
	{
		if( i % w < w - 1 )
			edges[ currEdge++ ] = { i, i + 1 };
		if( i / w < h - 1 )
			edges[ currEdge++ ] = { i, i + w };
	}
	currEdge = 0;
	shuffle( edges.begin( ), edges.end( ), default_random_engine( seed ) );
}

vector<pair<int, int>> Maze::edgeList( )
{
	return edges;
}

bool Maze::removeEdge( list<pair<int, int>> &l )
{
	while( currEdge < edges.size( ) && d.Find( edges[ currEdge ].first ) == d.Find( edges[ currEdge ].second ) )
		l.push_front( edges[ currEdge++ ] );
	if( currEdge == edges.size( ) )
		return 0;
	l.push_front( edges[ currEdge ] );
	d.Union( edges[ currEdge ].first, edges[ currEdge ].second );
	swap( edges[ currEdge ], edges[ edges.size( ) - 1 ] );
	edges.pop_back( );
	return 1;
}
