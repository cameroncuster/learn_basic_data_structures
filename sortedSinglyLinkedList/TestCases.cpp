#include "..\\catch.hpp"
#include "sortedSingle.h"
using namespace std;

TEST_CASE( "INTTEMPLATE" )
{
    sortedSingle<int> intlist;

    ostringstream intsout;

    // fill the list and compare with the string stream
    REQUIRE( intlist.insert( 10 ) == true );
    REQUIRE( intlist.insert( 20 ) == true );
    REQUIRE( intlist.insert( 30 ) == true );
    REQUIRE( intlist.insert( 40 ) == true );
    REQUIRE( intlist.insert( 50 ) == true );


    SECTION( "PRINT COMPARE" )
    {
        intlist.print( intsout );
        REQUIRE( intsout.str( ) == "10, 20, 30, 40, 50" );
    }

    // find the individual items in the linked list
    REQUIRE( intlist.find( 00 ) == false );
    REQUIRE( intlist.find( 10 ) == true );
    REQUIRE( intlist.find( 20 ) == true );
    REQUIRE( intlist.find( 30 ) == true );
    REQUIRE( intlist.find( 40 ) == true );
    REQUIRE( intlist.find( 50 ) == true );
    REQUIRE( intlist.find( 60 ) == false );
    
    // retrieve the position of the individual items in the list
    REQUIRE( intlist.retrievePosition( 00 ) == 0 );
    REQUIRE( intlist.retrievePosition( 10 ) == 1 );
    REQUIRE( intlist.retrievePosition( 20 ) == 2 );
    REQUIRE( intlist.retrievePosition( 30 ) == 3 );
    REQUIRE( intlist.retrievePosition( 40 ) == 4 );
    REQUIRE( intlist.retrievePosition( 50 ) == 5 );
    REQUIRE( intlist.retrievePosition( 60 ) == 0 );

    // remove the items from the list and compare with the string stream
    REQUIRE( intlist.remove( 00 ) == false );
    REQUIRE( intlist.remove( 10 ) == true );
    REQUIRE( intlist.remove( 50 ) == true );
    REQUIRE( intlist.remove( 20 ) == true );
    REQUIRE( intlist.remove( 30 ) == true );
    REQUIRE( intlist.remove( 40 ) == true );
    REQUIRE( intlist.remove( 10 ) == false );
    
    SECTION( "PRINT COMPARE" )
    {
        intlist.print( intsout );
        REQUIRE( intsout.str( ) == "" );
    }
}

TEST_CASE( "STRTEMPLATE" )
{
    sortedSingle<string> strlist;

    ostringstream strsout;

    // fill the list and compare with the string stream
    REQUIRE( strlist.insert( "a" ) == true );
    REQUIRE( strlist.insert( "b" ) == true );
    REQUIRE( strlist.insert( "c" ) == true );
    REQUIRE( strlist.insert( "d" ) == true );
    REQUIRE( strlist.insert( "e" ) == true );

    SECTION( "PRINT COMPARE" )
    {
        strlist.print( strsout );
        REQUIRE( strsout.str( ) == "a, b, c, d, e" );
    }

    // find the individual items in the list
    REQUIRE( strlist.find( "x" ) == false );
    REQUIRE( strlist.find( "a" ) == true );
    REQUIRE( strlist.find( "b" ) == true );
    REQUIRE( strlist.find( "c" ) == true );
    REQUIRE( strlist.find( "d" ) == true );
    REQUIRE( strlist.find( "e" ) == true );
    REQUIRE( strlist.find( "y" ) == false );
    
    // retrieve the position of the individual items in the list
    REQUIRE( strlist.retrievePosition( "x" ) == 0 );
    REQUIRE( strlist.retrievePosition( "a" ) == 1 );
    REQUIRE( strlist.retrievePosition( "b" ) == 2 );
    REQUIRE( strlist.retrievePosition( "c" ) == 3 );
    REQUIRE( strlist.retrievePosition( "d" ) == 4 );
    REQUIRE( strlist.retrievePosition( "e" ) == 5 );
    REQUIRE( strlist.retrievePosition( "y" ) == 0 );

    // remove the items from the list and compare with the string stream
    REQUIRE( strlist.remove( "x" ) == false );
    REQUIRE( strlist.remove( "a" ) == true );
    REQUIRE( strlist.remove( "b" ) == true );
    REQUIRE( strlist.remove( "c" ) == true );
    REQUIRE( strlist.remove( "d" ) == true );
    REQUIRE( strlist.remove( "e" ) == true );
    REQUIRE( strlist.remove( "y" ) == false );

    SECTION( "PRINT COMPARE" )
    {
        strlist.print( strsout );
        REQUIRE( strsout.str( ) == "" );
    }
}

TEST_CASE( "COPY CONSTRUCTOR<INT> _ EXTRA POINT" )
{
    sortedSingle<int> intlist;

    stringstream intsout;
    stringstream intsoutcpy;

    // empty lists
    SECTION( "EMPTY LISTS" )
    {
        sortedSingle<int> intlistcpy( intlist );
        intlist.print( intsout );
        intlistcpy.print( intsoutcpy );
        REQUIRE( intsoutcpy.str( ) == "" );
        REQUIRE( intsout.str( ) == intsoutcpy.str( ) );
    }

    // fill the base list with values
    CHECK( intlist.insert( 10 ) == true );
    CHECK( intlist.insert( 20 ) == true );
    CHECK( intlist.insert( 30 ) == true );
    CHECK( intlist.insert( 40 ) == true );
    CHECK( intlist.insert( 50 ) == true );

    // copy the base list
    sortedSingle<int> intlistcpy( intlist );

    // ensure the lists are complete copies of one another
    SECTION( "COPIED LIST OF VALUES" )
    {
        intlist.print( intsout );
        intlistcpy.print( intsoutcpy );
        REQUIRE( intsoutcpy.str( ) == "10, 20, 30, 40, 50" );
        REQUIRE( intsout.str( ) == intsoutcpy.str( ) );
    }

    // remove from the copy
    CHECK( intlistcpy.remove( 10 ) == true );
    CHECK( intlistcpy.remove( 50 ) == true );
    CHECK( intlistcpy.remove( 30 ) == true );

    // ensure the modified copies are not equal and verify their contents
    SECTION( "MODIFIED COPIES" )
    {
        intlist.print( intsout );
        intlistcpy.print( intsoutcpy );
        REQUIRE( intsout.str( ) == "10, 20, 30, 40, 50" );
        REQUIRE( intsoutcpy.str( ) == "20, 40" );
        REQUIRE( intsout.str( ) != intsoutcpy.str( ) );
    }
}

TEST_CASE( "COPY CONSTRUCTOR<STR> _ EXTRA POINT" )
{
    sortedSingle<string> strlist;

    stringstream strsout;
    stringstream strsoutcpy;

    // empty lists
    SECTION( "EMPTY LISTS" )
    {
        sortedSingle<string> strlistcpy( strlist );
        strlist.print( strsout );
        strlistcpy.print( strsoutcpy );
        REQUIRE( strsoutcpy.str( ) == "" );
        REQUIRE( strsout.str( ) == strsoutcpy.str( ) );
    }

    // fill the base list with values
    CHECK( strlist.insert( "a" ) == true );
    CHECK( strlist.insert( "b" ) == true );
    CHECK( strlist.insert( "c" ) == true );
    CHECK( strlist.insert( "d" ) == true );
    CHECK( strlist.insert( "e" ) == true );

    // copy the base list
    sortedSingle<string> strlistcpy( strlist );

    // ensure the lists are complete copies of one another
    SECTION( "COPIED LIST OF VALUES" )
    {
        strlist.print( strsout );
        strlistcpy.print( strsoutcpy );
        REQUIRE( strsoutcpy.str( ) == "a, b, c, d, e" );
        REQUIRE( strsout.str( ) == strsoutcpy.str( ) );
    }

    // remove from the copy
    CHECK( strlistcpy.remove( "a" ) == true );
    CHECK( strlistcpy.remove( "e" ) == true );
    CHECK( strlistcpy.remove( "c" ) == true );

    // ensure the modified copies are not equal and verify their contents
    SECTION( "MODIFIED COPIES" )
    {
        strlist.print( strsout );
        strlistcpy.print( strsoutcpy );
        REQUIRE( strsout.str( ) == "a, b, c, d, e" );
        REQUIRE( strsoutcpy.str( ) == "b, d" );
        REQUIRE( strsout.str( ) != strsoutcpy.str( ) );
    }
}
