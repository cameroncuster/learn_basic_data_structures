#include "maxStack.h"

bool MaxStack::empty() const
{
	return theStack.empty( );
}

int MaxStack::size() const
{
	return theStack.size( );
}

int MaxStack::top() const
{
	return theStack.back( );
}

void MaxStack::push(int item)
{
	if( empty( ) || max( ) <= item )
		theMaxStack.push_back( item );
	theStack.push_back( item );
}

void MaxStack::pop()
{
	if( !empty( ) )
	{
		if( max( ) == top( ) )
			theMaxStack.pop_back( );
		theStack.pop_back( );
	}
}

int MaxStack::max() const
{
	return theMaxStack.back( );
}

ostream& operator<<(ostream &os, const MaxStack &mst)
{
	int i, j;
	os << "MaxStack:" << '\n';
	j = mst.theMaxStack.size( ) - 1;
	for( i = mst.theStack.size( ) - 1; i >= 0; i-- )
	{
		os << mst.theStack[i] << ' ' << '[' << mst.theMaxStack[j] << ']' << '\n';
		if( mst.theStack[i] == mst.theMaxStack[j] )
			j--;
	}
	return os;
}
