#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class binaryHeap
{
    public:
        // constructor 
        binaryHeap( );
        // copy constructor with vector and heap

        const bool isEmpty( ) const;
        const int size( ) const;
        const int &top( ) const;
        void push( const int &x );
        void pop( );

        // DEBUG print with stringstream

    private:
        int currentSize;
        vector<int> arr;

        void percolateDown( int hole );
};
