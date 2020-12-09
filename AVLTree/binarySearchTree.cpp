#include <set>
#include <ctime>
#include <random>
#include "..//catch.hpp"
#include "binarySearchTree.h"

TEST_CASE( "CONSTRUCTOR" )
{
    binarySearchTree bst;

    REQUIRE( bst.empty( ) == true );
}

TEST_CASE( "ISEMPTY" )
{
    binarySearchTree bst;

    stringstream sout;
    
    REQUIRE( bst.empty( ) == true );
    
    bst.insert( 0 );

    REQUIRE( bst.empty( ) == false );
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

    SECTION( "SINGLE VALUE" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "0, " );
    }

    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 3 );
    bst.insert( 4 );
    bst.insert( 5 );

    SECTION( "MULTIPLE VALUES" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "0, 1, 2, 3, 4, 5, " );
    }

    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 3 );
    bst.insert( 4 );
    bst.insert( 5 );

    SECTION( "DUPLICATES" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "0, 1, 2, 3, 4, 5, " );
    }
}

TEST_CASE( "count" )
{
    binarySearchTree bst;

    SECTION( "EMPTY" )
    {
        REQUIRE( bst.count( 0 ) == false );
    }

    bst.insert( 0 );

    SECTION( "SINGLE VALUE" )
    {
        REQUIRE( bst.count( 0 ) == true );
        REQUIRE( bst.count( 1 ) == false );
    }

    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 3 );
    bst.insert( 4 );
    bst.insert( 5 );
    
    SECTION( "MULTIPLE VALUES" )
    {
        REQUIRE( bst.count( 6 ) == false );
        REQUIRE( bst.count( 0 ) == true );
        REQUIRE( bst.count( 1 ) == true );
        REQUIRE( bst.count( 2 ) == true );
        REQUIRE( bst.count( 3 ) == true );
        REQUIRE( bst.count( 4 ) == true );
        REQUIRE( bst.count( 5 ) == true );
        REQUIRE( bst.count( 7 ) == false );
    }
}

TEST_CASE( "FINDMIN" )
{
    binarySearchTree bst;
    
    stringstream sout;

    REQUIRE( bst.findMin( ) == NULL );

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

    REQUIRE( bst.findMax( ) == NULL );

    bst.insert( 3 );
    bst.insert( 1 );
    bst.insert( 2 );
    bst.insert( 4 );
    bst.insert( 5 );

    REQUIRE( bst.findMax( ) == 5 );
}

TEST_CASE( "erase" )
{
    binarySearchTree bst;

    stringstream sout;

    bst.erase( 0 );

    SECTION( "EMPTY" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "" );
    }

    bst.insert( 0 );

    bst.erase( 0 );

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

    bst.erase( 1 );

    SECTION( "VALUE BEGIN" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "2, 3, 4, 5, " );
    }

    bst.erase( 5 );

    SECTION( "VALUE END" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "2, 3, 4, " );
    }

    bst.erase( 3 );

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

    bst.erase( 3 );

    SECTION( "VALUE1" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "1, 2, 4, 5, " );
    }

    bst.insert( 6 );
    bst.insert( 7 );
    bst.insert( 8 );
    bst.insert( 0 );
    bst.insert( 13 );
    bst.insert( 31 );
    bst.insert( -1 );

    bst.erase( 31 );
    bst.erase( 0 );
    bst.erase( 6 );

    SECTION( "VALUE1" )
    {
        bst.print( sout );
        REQUIRE( sout.str( ) == "-1, 1, 2, 4, 5, 7, 8, 13, " );
    }
}

TEST_CASE( "COPY CONSTRUCTOR" )
{
    binarySearchTree bst;

    stringstream sout;
    stringstream soutcpy;

    SECTION( "EMPTY" )
    {
        binarySearchTree bstcpy( bst );
        bst.print( sout );
        bstcpy.print( soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }

    bst.insert( 0 );

    SECTION( "SINGLE VALUE" )
    {
        binarySearchTree bstcpy( bst );
        bst.print( sout );
        bstcpy.print( soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }

    bst.insert( 3 );
    bst.insert( 2 );
    bst.insert( 1 );
    bst.insert( 4 );
    bst.insert( 5 );

    SECTION( "MULTIPLE VALUES" )
    {
        binarySearchTree bstcpy( bst );
        bst.print( sout );
        bstcpy.print( soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }
}

TEST_CASE( "OVERLOADED EQUAL OPERATOR" )
{
    binarySearchTree bst;

    stringstream sout;
    stringstream soutcpy;

    SECTION( "EMPTY" )
    {
        binarySearchTree bstcpy = bst;
        bst.print( sout );
        bstcpy.print( soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }

    bst.insert( 0 );

    SECTION( "SINGLE VALUE" )
    {
        binarySearchTree bstcpy = bst;
        bst.print( sout );
        bstcpy.print( soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }

    bst.insert( 3 );
    bst.insert( 2 );
    bst.insert( 1 );
    bst.insert( 4 );
    bst.insert( 5 );

    SECTION( "MULTIPLE VALUES" )
    {
        binarySearchTree bstcpy = bst;
        bst.print( sout );
        bstcpy.print( soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }

    SECTION( "SAME TREES" )
    {
    }

    SECTION( "TREE WITH VALUES" )
    {
    }
}

TEST_CASE( "SIZE" )
{
    binarySearchTree bst;

    REQUIRE( bst.size( ) == NULL );

    bst.insert( 0 );
    bst.insert( 3 );
    bst.insert( 2 );
    bst.insert( 1 );
    bst.insert( 4 );
    bst.insert( 5 );

    REQUIRE( bst.size( ) == 6 );
}

void printSet( set<int> &s, stringstream &out, string seperator = ", " )
{
    for( auto node : s )
        out << node << seperator;
}

TEST_CASE( "BST VS STL" )
{
    srand( time( NULL ) );
    int i;
    int num;
    binarySearchTree bst;
    set<int> bstcpy;

    set<int>::iterator max;
    set<int>::iterator min;

    stringstream sout;
    stringstream soutcpy;

    SECTION( "EMPTY" )
    {
        bst.print( sout );
        printSet( bstcpy, soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }

    // 9000001
    for( i = 0; i < 100001; i++ )
    {
        num = ( rand( ) % 2000 );
        if( i % 2 == 0 )
        {
            bst.insert( num );
            bstcpy.insert( num );
        }
        else if( i % 2 == 1 )
        {
            bst.erase( num );
            bstcpy.erase( num );
        }
        CHECK( bst.empty( ) == bstcpy.empty( ) );
        CHECK( bst.size( ) == bstcpy.size( ) );
        CHECK( bst.count( num ) == bstcpy.count( num ) );
        min = bstcpy.begin( );
        max = bstcpy.end( );
        max--;
        CHECK( bst.findMin( ) == *min );
        CHECK( bst.findMax( ) == *max );
    }

    SECTION( "VALUES" )
    {
        bst.print( sout );
        printSet( bstcpy, soutcpy );
        REQUIRE( sout.str( ) == soutcpy.str( ) );
    }
}