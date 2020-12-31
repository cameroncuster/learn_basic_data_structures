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



const int &binaryHeap::top( ) const
{
    return arr[1];
}



void binaryHeap::push( const int &x )
{
    int hole = ++currentSize;
    if( currentSize == arr.size( ) - 1 )
        arr.resize( arr.size( ) * 2 );

    for( ; hole > 1 && x < arr[hole / 2]; hole /= 2 )
        arr[hole] = arr[hole / 2];
    arr[hole] = x;
}



void binaryHeap::pop( )
{
    if( isEmpty( ) )
        throw underflow_error( "Underflow exception thrown in pop<T>( ) binaryHeap is empty" );

    arr[1] = arr[currentSize--];
    percolateDown( 1 );
}

void binaryHeap::percolateDown( int hole )
{
    int child;
    int temp = arr[hole];

    for( ; hole * 2 <= currentSize; hole = child )
    {
        child = hole * 2;
        if( child != currentSize && arr[child + 1] < arr[child] )
            child++;
        if( arr[child] < temp )
            arr[hole] = arr[child];
        else
            break;
    }
    arr[hole] = temp;
}
