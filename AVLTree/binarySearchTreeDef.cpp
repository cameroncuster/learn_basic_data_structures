#include "binarySearchTree.h"

binarySearchTree::binarySearchTree( )
{
	root = nullptr;
}



binarySearchTree::binarySearchTree( const binarySearchTree &t )
{
    root = clone( t.root );
}



binarySearchTree::~binarySearchTree( )
{
	makeEmpty( root );
}



const binarySearchTree &binarySearchTree::operator=( const binarySearchTree &rhs ) 
{
	makeEmpty( );
	return binarySearchTree( rhs );
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



const void binarySearchTree::makeEmpty( )
{
	makeEmpty( root );
}



const void binarySearchTree::makeEmpty( node *&t )
{
	if( t != nullptr )
	{
		makeEmpty( t->left );
		makeEmpty( t->right );
		delete t;
	}
	t = nullptr;
}



const bool binarySearchTree::isEmpty( ) const
{
	return root == nullptr;
}



const void binarySearchTree::insert( const int x )
{
	insert( x, root );
}



const void binarySearchTree::insert( const int x, node *&t ) const
{
	if( t == nullptr )
	{
		t = new ( nothrow ) node;
		if( t == nullptr )
			exit( 1 );
		t->element = x;
		t->left = nullptr;
		t->right = nullptr;
	}
	else if( x < t->element )
		insert( x, t->left );
	else if( x > t->element )
		insert( x, t->right );
}



const void binarySearchTree::remove( const int x )
{
	remove( x, root );
}



const void binarySearchTree::remove( const int x, node *&t ) const
{
	if( t == nullptr )
		return;
	if( x < t->element )
		remove( x, t->left );
	else if( x > t->element )
		remove( x, t->right );
	else if( t->left != nullptr && t->right != nullptr )
	{
		t->element = findMin( t->right )->element;
		remove( t->element, t->right );
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
	}
}



const bool binarySearchTree::contains( const int &x ) const
{
	return contains( x, root );
}



bool binarySearchTree::contains( const int x, const node *t ) const
{
	if( t == nullptr )
		return false;
	else if( x < t->element )
		return contains( x, t->left );
	else if( x > t->element )
		return contains( x, t->right );
    return true;
}



const void binarySearchTree::print( ostream &out ) const
{
	print( root, out );
}



void binarySearchTree::print( const node *t, ostream &out, const string seperator ) const
{
	if( t == nullptr )
		return;

    print( t->left, out );
	out << t->element << seperator;
    print( t->right, out );
}
