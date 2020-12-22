#include "binaryHeap.h"

binaryHeap::binaryHeap( )
{
    currentSize = 0;
    nodeCount = 0;
}



/*
binaryHeap::binaryHeap( const binaryHeap &heap )
{
    currentSize = heap.size( );
    arr = items;
}
*/



const bool binaryHeap::isEmpty( ) const
{
    return nodeCount == 0;
}



void binaryHeap::insert( const int &x )
{
    int hole;
    if( currentSize == arr.size( ) - 1 )
        arr.resize( arr.size( ) * 2 );

    for( hole = currentSize++; hole > 1 && x < arr[hole / 2]; hole /= 2 )
        arr[hole] = arr[hole / 2];
    arr[hole] = x;
}

