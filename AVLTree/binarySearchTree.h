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

        const bool isEmpty( ) const;
        void insert( const int x );
        void remove( const int x );
        const bool contains( const int &x ) const;
        void makeEmpty( );
        void print( ostream &out ) const;

        const int findMin( ) const;
        const int findMax( ) const;

        const binarySearchTree &operator=( const binarySearchTree &rhs );

        // to complete with AVL ( utility )
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
        node *root;

        void insert( const int x, node *&t ) const;
        void remove( const int x, node *&t ) const;
        bool contains( const int x, const node *t ) const;
        void makeEmpty( node *&t );
        void print( const node *t, ostream &out, const string seperator = ", " ) const;

        // internal methods of finding the min and max in a subtree
        const node *findMin( const node *t ) const
        {
            if( t == nullptr )
                return nullptr;
            else if( t->left == nullptr )
                return t;
            return findMin( t->left );
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