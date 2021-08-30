#include "hashTable.h"
#include "../../catch.hpp"
#include <unordered_map>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

// random string excluding special characters
static const string alpha =
"1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string getRandStr( )
{
	int i;
	int len = rand( ) % 255;
	int x;
	string key;
	for( i = 0; i < len; i++ )
	{
		x = rand( ) % alpha.length( );
		key.push_back( alpha[x] );
	}
	return key;
}

list<string> getMapKeys( const unordered_map<string, int> &m )
{
	list<string> l;
	for( pair<string, int> x : m )
		l.push_back( x.first );
	return l;
}

TEST_CASE( "INSERT/SIZE/CONTAINS" )
{
	HashTable t( 2 );

	t.insert( "a", 0 );
	REQUIRE( t.size( ) == 1 );
	REQUIRE( t.containsKey( "a" ) == 1 );

	t.insert( "b", 1 );
	REQUIRE( t.size( ) == 2 );
	REQUIRE( t.containsKey( "a" ) == 1 );
	REQUIRE( t.containsKey( "b" ) == 1 );

	t.insert( "c", 2 );
	REQUIRE( t.size( ) == 3 );
	REQUIRE( t.containsKey( "a" ) == 1 );
	REQUIRE( t.containsKey( "b" ) == 1 );
	REQUIRE( t.containsKey( "c" ) == 1 );

	t.insert( "a", 1 );
	REQUIRE( t.size( ) == 3 );
	REQUIRE( t.containsKey( "a" ) == 1 );
	REQUIRE( t.containsKey( "b" ) == 1 );
	REQUIRE( t.containsKey( "c" ) == 1 );
}

TEST_CASE( "[]" )
{
	HashTable t;

	REQUIRE( t["a"] == 0 );

	t.insert( "a", 1 );
	REQUIRE( t["a"] == 1 );

	t.insert( "b", 1 );
	REQUIRE( t["a"] == 1 );
	REQUIRE( t["b"] == 1 );

	REQUIRE( ++t["c"] == 1 );

	t.insert( "c", 2 );
	REQUIRE( t["a"] == 1 );
	REQUIRE( t["b"] == 1 );
	REQUIRE( t["c"] == 2 );
}

TEST_CASE( "REMOVE" )
{
	HashTable t;

	t.insert( "a", 0 );
	t.insert( "b", 1 );
	t.insert( "c", 2 );

	t.remove( "c" );
	REQUIRE( t.containsKey( "c" ) == 0 );

	t.remove( "b" );
	REQUIRE( t.containsKey( "b" ) == 0 );

	t.remove( "a" );
	REQUIRE( t.containsKey( "a" ) == 0 );
}

TEST_CASE( "getKeys" )
{
	HashTable t;

	list<string> keys;
	list<string> ans = { "a", "b", "c", "d", "e" };

	t.insert( "a" );
	t.insert( "b" );
	t.insert( "c" );
	t.insert( "d" );
	t.insert( "e" );

	keys = t.getKeys( );

	keys.sort( );

	REQUIRE( keys == ans );
}

TEST_CASE( "SIZE OF LIST" )
{
	HashTable t( 1 );

	t.insert( "a" );

	REQUIRE( t.size( 1 ) == 1 );
}

TEST_CASE( "STL COMPARATIVE TESTING" )
{
	srand( time( NULL ) );
	int i;
	HashTable t;
	unordered_map<string, int> m;
	list<string> tkeys;
	list<string> mkeys;
	string key;
	int val;
	string prev;

	for( i = 0; i < 10001; i++ )
	{
		key = getRandStr( );
		val = rand( ) % 100;

		if( i % 10 || !i )
		{
			t.insert( key, val );
			m[key] = val;
			prev = key;
		}
		else if( i % 10 )
		{
			t.remove( prev );
			m.erase( prev );
		}

		tkeys = t.getKeys( );
		mkeys = getMapKeys( m );

		tkeys.sort( );
		mkeys.sort( );

		REQUIRE( t[key] == m[key] );
		REQUIRE( ( unsigned ) t.size( ) == m.size( ) );
		REQUIRE( t.containsKey( key ) == m.count( key ) );
		REQUIRE( tkeys == mkeys );
	}
}
