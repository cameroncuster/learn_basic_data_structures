#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <class TY>
class binaryHeap
{
    public:
        // constructor 
        binaryHeap( );
        // copy constructor with vector and heap

        const bool isEmpty( ) const;
        const int size( ) const;
        const TY &top( ) const;
        void push( const TY &x );
        void pop( );

        // DEBUG print with stringstream

    private:
        int currentSize;
        vector<TY> arr;

        // implement linear buildHeap function
        void percolateDown( int hole );
};



template <typename TY>
binaryHeap<TY>::binaryHeap( )
{
    arr.resize( 2 );
    currentSize = 0;
}



template <typename TY>
const bool binaryHeap<TY>::isEmpty( ) const
{
    return currentSize == 0;
}



template <typename TY>
const int binaryHeap<TY>::size( ) const
{
    return currentSize;
}



template <typename TY>
const TY &binaryHeap<TY>::top( ) const
{
    return arr[1];
}



template <typename TY>
void binaryHeap<TY>::push( const TY &x )
{
    int hole = ++currentSize;
    if( currentSize == arr.size( ) - 1 )
        arr.resize( arr.size( ) * 2 );

    for( ; hole > 1 && x < arr[hole / 2]; hole /= 2 )
        arr[hole] = arr[hole / 2];
    arr[hole] = x;
}



template <typename TY>
void binaryHeap<TY>::pop( )
{
    if( isEmpty( ) )
        throw underflow_error( "Underflow exception thrown in pop<T>( ) binaryHeap is empty" );

    arr[1] = arr[currentSize--];
    percolateDown( 1 );
}



template <typename TY>
void binaryHeap<TY>::percolateDown( int hole )
{
    int child;
    TY temp = arr[hole];

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
