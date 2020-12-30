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

TEST_CASE( "INSERT/EMPTY/SIZE/FINDMIN" )
{
    binaryHeap heap;

    heap.insert( 1 );

    REQUIRE( heap.isEmpty( ) == false );
    REQUIRE( heap.size( ) == 1 );
    REQUIRE( heap.findMin( ) == 1 );

    heap.insert( 2 );

    REQUIRE( heap.size( ) == 2 );
    REQUIRE( heap.findMin( ) == 1 );

    heap.insert( 0 );
    heap.insert( 1 );
    heap.insert( 2 );
    heap.insert( 3 );

    REQUIRE( heap.size( ) == 6 );
    REQUIRE( heap.findMin( ) == 0 );
}

TEST_CASE( "DELETEMIN" )
{
    binaryHeap heap;
    
    heap.insert( 0 );
    heap.insert( 1 );
    heap.insert( 2 );
    heap.insert( 3 );
    heap.insert( 4 );

    heap.deleteMin( );

    REQUIRE( heap.size( ) == 4 );

    heap.deleteMin( );

    REQUIRE( heap.size( ) == 3 );

    heap.deleteMin( );

    REQUIRE( heap.size( ) == 2 );

    heap.deleteMin( );

    REQUIRE( heap.size( ) == 1 );

    heap.deleteMin( );

    REQUIRE( heap.size( ) == 0 );

    // Test exception error message
    //heap.deleteMin( );
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
            heap.deleteMin( );
            //pq.deleteMin( );
        }
        */
        heap.insert( temp );
        pq.push( temp );
    }
}
