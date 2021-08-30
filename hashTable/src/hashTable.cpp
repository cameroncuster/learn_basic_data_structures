#include "hashTable.h"

using namespace std;

unsigned nextPrime( unsigned x )
{
	for( unsigned long i : primeList )
		if( i > x )
			return i;
	return ++x;
}

HashTable::HashTable( int cap )
{
	table.resize( nextPrime( cap ) );
	currSize = 0;
}

void HashTable::insert( string key, int value )
{
	list<pair<string, int>> &row = table[ hashFn( key ) ];
	list<pair<string, int>>::iterator it = findKey( row, key );
	if( it != row.end( ) )
	{
		it->second = value;
		return;
	}
	row.push_front( { key, value } );
	if( ++currSize > table.size( ) )
		rehash( );
}

void HashTable::remove( string key )
{
	list<pair<string, int>> &row = table[ hashFn( key ) ];
	list<pair<string, int>>::iterator it = findKey( row, key );
	if( it == row.end( ) )
		return;
	currSize--;
	row.erase( it );
}

int &HashTable::operator[]( string key )
{
	list<pair<string, int>> &row = table[ hashFn( key ) ];
	list<pair<string, int>>::iterator it = findKey( row, key );
	if( it == row.end( ) )
		insert( key, 0 );
	it = findKey( table[ hashFn( key ) ], key );
	return it->second;
}

bool HashTable::containsKey( string key ) const
{
	for( pair<string, int> x : table[ hashFn( key ) ] )
		if( x.first == key )
			return 1;
	return 0;
}

list<string> HashTable::getKeys( ) const
{
	list<string> keys;
	for( list<pair<string, int>> l : table )
		for( pair<string, int> x : l )
			keys.push_back( x.first );
	return keys;
}

int HashTable::size( ) const
{
	return currSize;
}

int HashTable::size( int i ) const
{
	if( ( unsigned ) i >= 0 && ( unsigned ) i < table.size( ) )
		return table[i].size( );
	return 0;
}

size_t HashTable::hashFn( string key ) const
{
	unsigned i;
	int hashVal = 0;

	for( i = 0; i < key.length( ); i++ )
		hashVal = 37 * hashVal + key[i];

	hashVal %= table.size( );
	if( hashVal < 0 )
		hashVal += table.size( );

	return hashVal;
}

int HashTable::tableSize( ) const
{
	return table.size( );
}

void HashTable::rehash( )
{
	unsigned i = 0;
	unsigned n = nextPrime( 2 * table.size( ) );
	vector<list<pair<string, int>>> prevTable = table;

	cout << "Rehashing:: Load Factor = " << ( double ) currSize /
		( double ) table.size( ) << " new table size = " << n << endl;

	table.resize( n );
	for( i = 0; i < prevTable.size( ); i++ )
		table[i].clear( );

	currSize = 0;
	for( list<pair<string, int>> l : prevTable )
		for( pair<string, int> x : l )
			insert( x.first, x.second );
}

list<pair<string, int>>::iterator HashTable::findKey( list<pair<string, int>> &l,
		const string &key ) const
{
	list<pair<string, int>>::iterator it = l.begin( );
	for( ; it != l.end( ) && it->first != key; it++ );
	return it;
}
