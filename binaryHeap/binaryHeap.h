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
        // priority queue

        const bool isEmpty( ) const;
        // size function

        // percolate up and percolate down
        void insert( const int &x );
        // getmin function
        void deleteMin( );
        void deleteMin( int &x );
        void makeEmpty( );

    private:
        int currentSize;
        vector<int> arr;
        int nodeCount;
};
