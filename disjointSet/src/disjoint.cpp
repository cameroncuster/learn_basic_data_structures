#include "disjoint.h"

using namespace std;

Disjoint::Disjoint( int cap )
{
	size = cap;
	ds.resize( size, -1 );
}

int Disjoint::Find( int v )
{
	if( ds[v] < 0 )
		return v;

	ds[v] = Find( ds[v] );
	return ds[v];
}

void Disjoint::Union( int i, int j )
{
	i = Find( i );
	j = Find( j );

	if( i == j )
		return;

	size--;
	if( ds[i] < ds[j] )
	{
		ds[i] += ds[j];
		ds[j] = i;
	}
	else
	{
		ds[j] += ds[i];
		ds[i] = j;
	}
	return;
}

int Disjoint::setCount() const
{
	return size;
}
