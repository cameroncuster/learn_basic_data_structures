#include "graph.h"

using namespace std;

static const constexpr short delta[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

Graph::Graph() { }

Graph::Graph(istream &instream) : numVertices(0), numEdges(0)
{
	int v, w;
	while (!instream.eof())
	{
		instream >> v >> w;
		addEdge(v, w);
	}

	numVertices = vertices.size();
	for (int u : Vertices())
		numEdges += adj(u).size();

	numEdges /= 2;
}

Graph::Graph(const vector<vector<int>> &grid) : numVertices( 0 ), numEdges( 0 )
{
	unsigned i, j;
	unsigned w = grid[0].size( );
	unsigned h = grid.size( );
	for( i = 0; i < h; i++ )
		for( j = 0; j < w; j++ )
		{
			if( j < w - 1 )
				if( grid[i][j] && grid[i][j + 1] )
					addEdge( i * w + j, i * w + j + 1 );
			if( i < h - 1 )
				if( grid[i][j] && grid[i + 1][j] )
					addEdge( i * w + j, ( i + 1 ) * w + j );
		}
	numVertices = vertices.size();
	for (int u : Vertices())
		numEdges += adj(u).size();

	numEdges /= 2;
}

Graph::~Graph() {}

int Graph::V() const { return numVertices ; }
int Graph::E() const { return numEdges ; }

set<int> Graph::Vertices() const
{
	set<int> retVal;
	for (auto &kv : vertices)
		retVal.insert(kv.first);

	return retVal;
}

set<int> Graph::adj(int v)
{
	return vertices[v];
}

// This implementation of addEdge presumes the graph is undirected
void Graph::addEdge(int v, int w)
{
	vertices[v].insert(w);
	vertices[w].insert(v);
}
