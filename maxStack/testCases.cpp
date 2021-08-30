#include <sstream>
#include "..//catch.hpp"
#include "maxStack.h"

TEST_CASE( "EMPTY" )
{
	MaxStack myMaxStack;

	REQUIRE( myMaxStack.empty( ) == 1 );
}

TEST_CASE( "SIZE" )
{
	MaxStack myMaxStack;

	REQUIRE( myMaxStack.size( ) == 0 );
}

TEST_CASE( "PUSH/TOP/PRINT" )
{
	MaxStack myMaxStack;

	myMaxStack.push( 1 );
	REQUIRE( myMaxStack.top( ) == 1 );
	myMaxStack.push( 2 );
	REQUIRE( myMaxStack.top( ) == 2 );
	myMaxStack.push( 3 );
	REQUIRE( myMaxStack.top( ) == 3 );
}

TEST_CASE( "POP/TOP/PRINT" )
{
	MaxStack myMaxStack;

	myMaxStack.pop( );

	myMaxStack.push( 1 );
	REQUIRE( myMaxStack.top( ) == 1 );
	myMaxStack.push( 2 );
	REQUIRE( myMaxStack.top( ) == 2 );
	myMaxStack.push( 3 );
	REQUIRE( myMaxStack.top( ) == 3 );

	myMaxStack.pop( );
	REQUIRE( myMaxStack.top( ) == 2 );
	myMaxStack.pop( );
	REQUIRE( myMaxStack.top( ) == 1 );
	myMaxStack.pop( );

	REQUIRE( myMaxStack.empty( ) == 1 );
}

TEST_CASE( "MAX" )
{
	MaxStack myMaxStack;

	myMaxStack.push( 1 );
	REQUIRE( myMaxStack.max( ) == 1 );
	myMaxStack.push( 2 );
	REQUIRE( myMaxStack.max( ) == 2 );
	myMaxStack.push( 3 );
	REQUIRE( myMaxStack.max( ) == 3 );
	myMaxStack.push( 0 );
	REQUIRE( myMaxStack.max( ) == 3 );
	myMaxStack.push( 2 );
	REQUIRE( myMaxStack.max( ) == 3 );
	myMaxStack.push( 5 );
	REQUIRE( myMaxStack.max( ) == 5 );
	myMaxStack.pop( );
	REQUIRE( myMaxStack.max( ) == 3 );
	myMaxStack.pop( );
	REQUIRE( myMaxStack.max( ) == 3 );
	myMaxStack.pop( );
	REQUIRE( myMaxStack.max( ) == 3 );
	myMaxStack.pop( );
	REQUIRE( myMaxStack.max( ) == 2 );
	myMaxStack.pop( );
	REQUIRE( myMaxStack.max( ) == 1 );
}

TEST_CASE( "PRINT" )
{
	MaxStack myMaxStack;
	stringstream sout;

	SECTION( "++0" )
	{
		sout << myMaxStack;
	}
	myMaxStack.push( 1 );
	SECTION( "++1" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n1 [1]\n" );
	}
	myMaxStack.push( 2 );
	SECTION( "++2" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.push( 3 );
	SECTION( "++3" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.push( 0 );
	SECTION( "++4" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n0 [3]\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.push( 2 );
	SECTION( "++5" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n2 [3]\n0 [3]\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.push( 5 );
	SECTION( "++6" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n5 [5]\n2 [3]\n0 [3]\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.pop( );
	SECTION( "--5" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n2 [3]\n0 [3]\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.pop( );
	SECTION( "--4" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n0 [3]\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.pop( );
	SECTION( "--3" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n3 [3]\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.pop( );
	SECTION( "--2" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n2 [2]\n1 [1]\n" );
	}
	myMaxStack.pop( );
	SECTION( "--1" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n1 [1]\n" );
	}
	myMaxStack.pop( );
	SECTION( "--0" )
	{
		sout << myMaxStack;
		REQUIRE( sout.str( ) == "MaxStack:\n" );
	}
	myMaxStack.pop( );
}
