#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class binaryHeap
{
    public:
        // constructor and destructor
        binaryHeap( );
        binaryHeap( const vector<int> &items );

        const bool isEmpty( ) const;

        void insert( const int &x );

    private:
        int currentSize;
        vector<int> arr;
        int nodeCount;
};
