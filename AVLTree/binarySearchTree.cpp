#include "..//catch.hpp"
#include "binarySearchTree.h"

// insert and remove duplicates
// loop 1000 times and randomly insert/remove a number from the tree
// number is 1 to 100 random
// compare the output to an STL set, ensure they match
TEST_CASE( "CONSTRUCTOR" )
{
    binarySearchTree bst;

    REQUIRE( bst.isEmpty( ) == true );
}

TEST_CASE( "ISEMPTY" )
{
    binarySearchTree bst;

    stringstream sout;
    
    REQUIRE( bst.isEmpty( ) == true );
    
    bst.insert( 0 );

    REQUIRE( bst.isEmpty( ) == false );
}

TEST_CASE( "INSERT/PRINT" )
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
        REQUIRE( sout.str( ) == "0, 1, 2, 3, 4, 5, " );
    }
}

TEST_CASE( "CONTAINS" )
{
    binarySearchTree bst;

    SECTION( "EMPTY" )
    {
        REQUIRE( bst.contains( 0 ) == false );
    }

    bst.insert( 0 );

    SECTION( "VALUE" )
    {
        REQUIRE( bst.contains( 0 ) == true );
        REQUIRE( bst.contains( 1 ) == false );
    }

    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 3 );
    bst.insert( 4 );
    bst.insert( 5 );
    
    SECTION( "VALUES" )
    {
        REQUIRE( bst.contains( 6 ) == false );
        REQUIRE( bst.contains( 0 ) == true );
        REQUIRE( bst.contains( 1 ) == true );
        REQUIRE( bst.contains( 2 ) == true );
        REQUIRE( bst.contains( 3 ) == true );
        REQUIRE( bst.contains( 4 ) == true );
        REQUIRE( bst.contains( 5 ) == true );
        REQUIRE( bst.contains( 7 ) == false );
    }
}

TEST_CASE( "FINDMIN" )
{
    binarySearchTree bst;
    
    stringstream sout;

    REQUIRE( bst.findMin( ) == 0 );

    bst.insert( 3 );
    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 4 );
    bst.insert( 5 );

    REQUIRE( bst.findMin( ) == 1 );
}

TEST_CASE( "FINDMAX" )
{
    binarySearchTree bst;
    
    stringstream sout;

    REQUIRE( bst.findMax( ) == 0 );

    bst.insert( 3 );
    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 4 );
    bst.insert( 5 );

    REQUIRE( bst.findMax( ) == 5 );
}

TEST_CASE( "REMOVE" )
{
    binarySearchTree bst;

    stringstream sout;

    bst.remove( 0 );

    SECTION( "EMPTY" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "" );
    }

    bst.insert( 0 );

    bst.remove( 0 );

    SECTION( "VALUE TO EMPTY" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "" );
    }

    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 3 );
    bst.insert( 4 );
    bst.insert( 5 );

    bst.remove( 1 );

    SECTION( "VALUE BEGIN" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "2, 3, 4, 5, " );
    }

    bst.remove( 5 );

    SECTION( "VALUE END" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "2, 3, 4, " );
    }

    bst.remove( 3 );

    SECTION( "VALUE" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "2, 4, " );
    }

    // TEST CASES DERIVED BASED ON CHILDREN COUNT

    bst.insert( 3 );
    bst.insert( 2 );
    bst.insert( 1 );
    bst.insert( 4 );
    bst.insert( 5 );

    bst.remove( 3 );

    SECTION( "VALUE1" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "1, 2, 4, 5, " );
    }
}