#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class binaryHeap
{
    public:
        // constructor and destructor
        binaryHeap( );
        // copy constructor with vector and heap

        const bool isEmpty( ) const;
        const int size( ) const;
        const int &findMin( ) const;

        // percolate up and percolate down
        void insert( const int &x );
        // getmin function
        void deleteMin( );
        void deleteMin( int &minval );
        void clear( );

        // DEBUG print with stringstream

    private:
        int currentSize;
        vector<int> arr;
};
