#include "..//catch.hpp"
#include "binarySearchTree.h"

TEST_CASE( "CONSTRUCTOR" )
{
    binarySearchTree bst;

    REQUIRE( bst.isEmpty( ) == true );
}

TEST_CASE( "INSERT" )
{
    binarySearchTree bst;

    stringstream sout;
    
    SECTION( "EMPTY" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "" );
    }

    bst.insert( 0 );

    SECTION( "VALUE" )
    {
        bst.print( sout );
        REQUIRE( bst.isEmpty( ) == false );
        REQUIRE( sout.str( ) == "0, " );
    }

    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 3 );
    bst.insert( 4 );
    bst.insert( 5 );

    SECTION( "VALUES" )
    {
        bst.print( sout );
        REQUIRE( bst.isEmpty( ) == false );
        REQUIRE( sout.str( ) == "0, 1, 2, 3, 4, 5, " );
    }
}

TEST_CASE( "REMOVE" )
{
    binarySearchTree bst;

    stringstream sout;
}