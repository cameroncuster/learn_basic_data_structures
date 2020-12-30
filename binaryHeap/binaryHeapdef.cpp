#include "binaryHeap.h"

binaryHeap::binaryHeap( )
{
    arr.resize( 2, 0 );
    currentSize = 0;
}



const bool binaryHeap::isEmpty( ) const
{
    return currentSize == 0;
}



const int binaryHeap::size( ) const
{
    return currentSize;
}



const int &binaryHeap::findMin( ) const
{
    return arr[1];
}



void binaryHeap::insert( const int &x )
{
    int hole = ++currentSize;
    if( currentSize == arr.size( ) - 1 )
        arr.resize( arr.size( ) * 2 );

    for( ; hole > 1 && x < arr[hole / 2]; hole /= 2 )
        arr[hole] = arr[hole / 2];
    arr[hole] = x;
}
