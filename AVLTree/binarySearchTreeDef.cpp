#include "binarySearchTree.h"

binarySearchTree::binarySearchTree( )
{
	root = nullptr;
}



binarySearchTree::~binarySearchTree( )
{
	makeEmpty( root );
}



int binarySearchTree::findMin( )
{
	if( findMin( root ) != nullptr )
		return findMin( root )->element;
	return 0;
}



int binarySearchTree::findMax( )
{
	if( findMax( root ) != nullptr )
		return findMax( root )->element;
	return 0;
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
        // handle case where t has children
    }
    // go to parent of t point it to the single child of t, delete t
}



bool binarySearchTree::contains( int x )
{
	return contains( x, root );
}



bool binarySearchTree::contains( int x, node *t )
{
	if( t == nullptr )
		return false;
	else if( x < t->element )
		return contains( x, t->left );
	else if( x > t->element )
		return contains( x, t->right );
    return true;
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
