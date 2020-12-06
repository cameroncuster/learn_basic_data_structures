#include "binarySearchTree.h"

binarySearchTree::binarySearchTree( )
{
	root = nullptr;
}



binarySearchTree::~binarySearchTree( )
{
	makeEmpty( root );
}



void binarySearchTree::makeEmpty( )
{
	makeEmpty( root );
}



void binarySearchTree::makeEmpty( node *&t )
{
	if( t != nullptr )
	{
		makeEmpty( t->left );
		makeEmpty( t->right );
		delete t;
	}
	t = nullptr;
}



bool binarySearchTree::isEmpty( ) const
{
	return root == nullptr;
}



void binarySearchTree::insert( int x )
{
	insert( x, root );
}



void binarySearchTree::insert( int x, node *&t )
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



void binarySearchTree::remove( int x )
{
	remove( x, root );
}



void binarySearchTree::remove( int x, node *&t )
{
	if( t == nullptr )
		return;
	if( x < t->element )
		remove( x, t->left );
	else if( x > t->element )
		remove( x, t->right );
	else if( t->left != nullptr && t->right != nullptr )
	{
		// find the smallest value on the right and put it in the hole then delete that node
	}
	else
	{
		// check if the subtree has one child, handle that case then delete
	}
}



void binarySearchTree::print( ostream &out )
{
	print( root, out );
}



void binarySearchTree::print( node *&t, ostream &out, string seperator )
{
	if( t == nullptr )
		return;

    print( t->left, out );
	out << t->element << seperator;
    print( t->right, out );
}
