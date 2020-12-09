#include "binarySearchTree.h"

/** ***************************************************************************
* constructor and destructor
* ****************************************************************************/
binarySearchTree::binarySearchTree( )
{
	root = nullptr;
	nodeCount = 0;
}



binarySearchTree::binarySearchTree( const binarySearchTree &t )
{
    root = clone( t.root );
	nodeCount = t.nodeCount;
}



binarySearchTree::~binarySearchTree( )
{
	clear( root );
}



/** ***************************************************************************
* appends
* ****************************************************************************/
void binarySearchTree::insert( const int &x, node *&t ) 
{
	if( t == nullptr )
	{
		t = new ( nothrow ) node;
		if( t == nullptr )
			exit( 1 );
		t->element = x;
		t->left = nullptr;
		t->right = nullptr;
        nodeCount++;
	}
	else if( x < t->element )
		insert( x, t->left );
	else if( x > t->element )
		insert( x, t->right );
}



void binarySearchTree::insert( const int &x )
{
	insert( x, root );
}



void binarySearchTree::erase( const int &x, node *&t )
{
	if( t == nullptr )
		return;
	if( x < t->element )
		erase( x, t->left );
	else if( x > t->element )
		erase( x, t->right );
	else if( t->left != nullptr && t->right != nullptr )
	{
		t->element = findMin( t->right )->element;
		erase( t->element, t->right );
    }
	else
	{
		if( t->left == nullptr )
		{
			node *temp = t->right;
			delete t;
			t = temp;
		}
		else if( t->right == nullptr )
		{
			node *temp = t->left;
			delete t;
			t = temp;
		}
		nodeCount--;
	}
}



void binarySearchTree::erase( const int &x )
{
	erase( x, root );
}



void binarySearchTree::clear( node *&t )
{
	if( t != nullptr )
	{
		clear( t->left );
		clear( t->right );
		delete t;
	}
	t = nullptr;
}



void binarySearchTree::clear( )
{
	clear( root );
}



/** ***************************************************************************
* verification
* ****************************************************************************/
const bool binarySearchTree::empty( ) const
{
	return root == nullptr;
}



const bool binarySearchTree::count( const int x, const node *t ) const
{
	if( t == nullptr )
		return false;
	else if( x < t->element )
		return count( x, t->left );
	else if( x > t->element )
		return count( x, t->right );
    return true;
}



const bool binarySearchTree::count( const int &x ) const
{
	return count( x, root );
}



const int binarySearchTree::size( const node *t ) const
{
	if( t == nullptr )
		return NULL;
	return nodeCount;
}



const int binarySearchTree::size( ) const
{
	return size( root );
}



const int binarySearchTree::findMin( ) const
{
	if( findMin( root ) != nullptr )
		return findMin( root )->element;
	return NULL;
}



const int binarySearchTree::findMax( ) const
{
	if( findMax( root ) != nullptr )
		return findMax( root )->element;
	return NULL;
}



/** ***************************************************************************
* debugging
* ****************************************************************************/
void binarySearchTree::print( const node *t, ostream &out, const string seperator ) const
{
	if( t == nullptr )
		return;

    print( t->left, out );
	out << t->element << seperator;
    print( t->right, out );
}



void binarySearchTree::print( ostream &out ) const
{
	print( root, out );
}



/** ***************************************************************************
* overloaded operators
* ****************************************************************************/
const binarySearchTree &binarySearchTree::operator=( const binarySearchTree &rhs ) 
{
	clear( );
	return binarySearchTree( rhs );
}
