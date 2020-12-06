#include <iostream>
#include <sstream>
using namespace std;

// implement as an STL version set
class binarySearchTree
{
	public:
        binarySearchTree( );
        binarySearchTree( const binarySearchTree &t );
        ~binarySearchTree( );

        bool isEmpty( ) const;
        void makeEmpty( );
        void insert( int x );
        void remove( int x );
        bool contains( int x );
        int size( );
        int length( ); 

        // to complete later
        int upperBound( int keyBound ); // returns the smallest key in the tree such that key > x ( log n )
        int lowerBound( int keyBound ); // returns the smallest key that could also be equal ( log n )
        int keybyorder( int i ); // return the ith largest key ( log n )
        int orderofkey( int key ); // returns the number of keys less than the key param ( log n )

        // DEBUGGING PURPOSES ONLY
        void print( ostream &out );
        
	private:
        struct node
        {
            int element;
            node *left;
            node *right;
        };
        node *root;

        void makeEmpty( node *&t );
        void balance( node *parent, node *child ); // store pointers into a temp node and then reassign constant
        void print( node *&t, ostream &out, string seperator = ", " );
        void insert( int x, node *&t );
        void remove( int x, node *&t );
};