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
* height
* ****************************************************************************/
const int binarySearchTree::height( const node *t ) const
{
    if( t == nullptr )
        return -1;
    return t->height;
}



/** ***************************************************************************
* rotations
* ****************************************************************************/
void binarySearchTree::rotateWithLeftChild( node *&k2 )
{
    node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k2->left ), k2->height ) + 1;
    k2 = k1;
}



void binarySearchTree::rotateWithRightChild( node *&k1 )
{
    node *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->right ), height( k1->left ) ) + 1;
    k2->height = max( height( k1->right ), k1->height ) + 1;
    k1 = k2;
}



void binarySearchTree::doubleWithLeftChild( node *&k3 )
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}



void binarySearchTree::doubleWithRightChild( node *&k1 )
{
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
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
    {
        insert( x, t->left );
        if( height( t->left ) - height( t->right ) == 2 )
		{
            if( x < t->left->element )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
		}
    }
    else if( x > t->element )
    {
        insert( x, t->right );
        if( height( t->right ) - height( t->left ) == 2 )
		{
            if( x > t->right->element )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
		}
    }
    t->height = max( height( t->left ), height( t->right ) ) + 1;
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
    if( t != nullptr )
    {
        if( height( t->left ) - height( t->right ) == 2 )
            if( x < t->left->element )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else if( height( t->right ) - height( t->left ) == 2 )
            if( x > t->right->element )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
        t->height = max( height( t->left ), height( t->right ) ) + 1;
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
    const node *min = findMin( root );
    return min != nullptr ? min->element : NULL; // throw exception if called on empty
}



const int binarySearchTree::findMax( ) const
{
    const node *max = findMax( root );
    return max != nullptr ? max->element : NULL; // throw exception if called on empty
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
