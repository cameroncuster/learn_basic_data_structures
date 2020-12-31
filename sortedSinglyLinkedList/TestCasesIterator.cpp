#include "..\\catch.hpp"
#include "sortedSingle.h"
using namespace std;

TEST_CASE( "INTITERATOR" )
{
    sortedSingle<int> list1;
    sortedSingle<int>::iterator it;

    ostringstream sout1;

    // fill the list and set the iterator to the beginning
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    it = list1.begin( );

    // validate the pre_increment utilizing an output string stream
    SECTION( "PRE_INCREMENT" )
    {
        while( it != list1.end( ) )
        {
            sout1 << *it;
            ++it;
            if( it != list1.end( ) )
                sout1 << ", ";
        }
        REQUIRE( sout1.str( ) == "10, 20, 30, 40, 50" );
    }

    // validate the post_increment utilizing an output string stream
    SECTION( "POST_INCREMENT" )
    {
        while( it != list1.end( ) )
        {
            sout1 << *it;
            it++;
            if( it != list1.end( ) )
                sout1 << ", ";
        }
        REQUIRE( sout1.str( ) == "10, 20, 30, 40, 50" );
    }

    // validate the equality comparison operators ( == & != )
    SECTION( "EQUALITY&!" )
    {
        sortedSingle<int>::iterator it1 = list1.begin( );
        sortedSingle<int>::iterator it2 = list1.begin( );
        sortedSingle<int>::iterator it3 = list1.end( );

        REQUIRE( it1 == it2 );
        REQUIRE( it1 != it3 );
        REQUIRE( it2 != it3 );
    }

    // validate the derefrence ( * )
    SECTION( "DEREFRENCE" )
    {
        it = list1.begin( );
        *it = 9;

        for( it = list1.begin( ); it != list1.end( ); it++ )
            sout1 << *it << ' ';
        REQUIRE( sout1.str( ) == "9 20 30 40 50 " );
    }

    // validate the derefrence too - >
    SECTION( "DEREFRENCE_RETURN_VAL" )
    {
        int n;
        n = *it;
        REQUIRE( n == 10 );
        n = *it++;
        REQUIRE( n == 10 );
    }

    // validate the address returned of the value located at the iterator
    SECTION( "ADDRESS_OF_ITEM" )
    {
        it = list1.begin( );
        ++it;
        it++;

        *it = 35;
        for( it = list1.begin( ); it != list1.end( ); ++it )
            sout1 << *it << ' ';
        REQUIRE( sout1.str( ) == "10 20 35 40 50 " );
    }
}

TEST_CASE( "STRITERATOR" )
{
    sortedSingle<string> list1;
    sortedSingle<string>::iterator it;

    ostringstream sout1;

    // fill the list and set the iterator to the beginning
    list1.insert( "a" );
    list1.insert( "b" );
    list1.insert( "c" );
    list1.insert( "d" );
    list1.insert( "e" );

    it = list1.begin( );

    // validate the pre_increment utilizing an output string stream
    SECTION( "PRE_INCREMENT" )
    {
        while( it != list1.end( ) )
        {
            sout1 << *it;
            ++it;
            if( it != list1.end( ) )
                sout1 << ", ";
        }
        REQUIRE( sout1.str( ) == "a, b, c, d, e" );
    }

    // validate the post_increment utilizing an output string stream
    SECTION( "POST_INCREMENT" )
    {
        while( it != list1.end( ) )
        {
            sout1 << *it;
            it++;
            if( it != list1.end( ) )
                sout1 << ", ";
        }
        REQUIRE( sout1.str( ) == "a, b, c, d, e" );
    }

    // validate the equality comparison operators ( == & != )
    SECTION( "EQUALITY&!" )
    {
        sortedSingle<string>::iterator it1 = list1.begin( );
        sortedSingle<string>::iterator it2 = list1.begin( );
        sortedSingle<string>::iterator it3 = list1.end( );

        REQUIRE( it1 == it2 );
        REQUIRE( it1 != it3 );
        REQUIRE( it2 != it3 );
    }

    // validate the derefrence ( * )
    SECTION( "DEREFRENCE" )
    {
        it = list1.begin( );
        *it = "z";

        for( it = list1.begin( ); it != list1.end( ); it++ )
            sout1 << *it << ' ';
        REQUIRE( sout1.str( ) == "z b c d e " );
    }

    // validate the derefrence too - >
    SECTION( "DEREFRENCE_RETURN_VAL" )
    {
        string n;
        n = *it;
        REQUIRE( n == "a" );
        n = *it++;
        REQUIRE( n == "a" );
    }

    // validate the address returned of the value located at the iterator
    SECTION( "ADDRESS_OF_ITEM" )
    {
        it = list1.begin( );
        ++it;
        it++;

        *it = "z";
        for( it = list1.begin( ); it != list1.end( ); ++it )
            sout1 << *it << ' ';
        REQUIRE( sout1.str( ) == "a b z d e " );
    }
}