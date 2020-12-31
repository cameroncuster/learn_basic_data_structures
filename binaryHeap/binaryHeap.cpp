#include <queue>
#include <random>
#include <ctime>
#include "..//catch.hpp"
#include "binaryHeap.h"

TEST_CASE( "CONSTRUCTOR" )
{
    binaryHeap heap;

    REQUIRE( heap.isEmpty( ) == true );
}

TEST_CASE( "PUSH/EMPTY/SIZE/TOP" )
{
    binaryHeap heap;

    heap.push( 1 );

    REQUIRE( heap.isEmpty( ) == false );
    REQUIRE( heap.size( ) == 1 );
    REQUIRE( heap.top( ) == 1 );

    heap.push( 2 );

    REQUIRE( heap.size( ) == 2 );
    REQUIRE( heap.top( ) == 1 );

    heap.push( 0 );
    heap.push( 1 );
    heap.push( 2 );
    heap.push( 3 );

    REQUIRE( heap.size( ) == 6 );
    REQUIRE( heap.top( ) == 0 );
}

TEST_CASE( "POP" )
{
    binaryHeap heap;
    
    heap.push( 0 );
    heap.push( 1 );
    heap.push( 2 );
    heap.push( 3 );
    heap.push( 4 );

    heap.pop( );

    REQUIRE( heap.size( ) == 4 );

    heap.pop( );

    REQUIRE( heap.size( ) == 3 );

    heap.pop( );

    REQUIRE( heap.size( ) == 2 );

    heap.pop( );

    REQUIRE( heap.size( ) == 1 );

    heap.pop( );

    REQUIRE( heap.size( ) == 0 );

    // Test exception error message
    //heap.pop( );
}

TEST_CASE( "PRIORITY_QUEUE VS BINARYHEAP" )
{
    int i;
    int temp;
    binaryHeap heap;
    priority_queue<int> pq;

    srand( time( NULL ) );
    for( i = 1; i < 1000; i++ )
    {
        temp = rand( ) % 100;
        /*
        if( i % 5 == 0 )
        {
            heap.pop( );
            //pq.pop( );
        }
        */
        heap.push( temp );
        pq.push( temp );
        REQUIRE( heap.isEmpty( ) == pq.empty( ) );
        REQUIRE( heap.size( ) == pq.size( ) );
        REQUIRE( heap.top( ) == pq.top( ) );
    }
}
