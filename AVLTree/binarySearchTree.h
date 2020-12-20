#include <iostream>
#include <sstream>
using namespace std;

// STL implementation of MAP or SET
class binarySearchTree
{
	public:
        // constructor and destructor
        binarySearchTree( );
        binarySearchTree( const binarySearchTree &t );
        ~binarySearchTree( );

        // appends
        void insert( const int &x );
        void erase( const int &x );
        void clear( );

        // verification
        const bool empty( ) const;
        const bool count( const int &x ) const;
        const int size( ) const;
        const int findMin( ) const;
        const int findMax( ) const;

        // overloaded operators
        const binarySearchTree &operator=( const binarySearchTree &rhs );

        // print routine for debugging
        void print( ostream &out ) const;

        // to complete with AVL ( utilities )
        int upperBound( int keyBound ); // returns the smallest key in the tree such that key > x ( log n )
        int lowerBound( int keyBound ); // returns the smallest key that could also be equal ( log n )
        int keybyorder( int i ); // return the ith largest key ( log n )
        int orderofkey( int key ); // returns the number of keys less than the key param ( log n )
        
	private:
        struct node
        {
            int element;
            node *left;
            node *right;
            int height;
        };
        int nodeCount;
        node *root;

        // retrieve the height of a node
        const int height( const node *t ) const;

        // AVLTree rotation routines
        void rotateWithLeftChild( node *&k2 );
        void rotateWithRightChild( node *&k1 ); 
        void doubleWithLeftChild( node *&k3 );
        void doubleWithRightChild( node *&k1 );

        // private append routines
        void insert( const int &x, node *&t );
        void erase( const int &x, node *&t );
        void clear( node *&t );

        // verification 
        const bool count( const int x, const node *t ) const;
        const int size( const node *t ) const;

        // print routine for debugging
        void print( const node *t, ostream &out, const string seperator = ", " ) const;

        // internal methods of finding the min and max in a subtree
        const node *findMin( const node *t ) const
        {
            if( t == nullptr )
                return nullptr;
            else if( t->left == nullptr )
                return t;
            return findMin( t->left );
            // balancing has to be done here
        }



        const node *findMax( const node *t ) const
        {
            if( t == nullptr )
                return nullptr;
            else if( t->right == nullptr )
                return t;
            return findMax( t->right );
        }



        // internal method of copying the tree
        node *clone( const node *t ) const
        {
            if( t == nullptr )
                return nullptr;

            node *temp = new ( nothrow ) node;
            if( temp == nullptr )
                return nullptr;
            temp->element = t->element;
            temp->left = clone( t->left );
            temp->right = clone( t->right );
            return temp;
        }
};