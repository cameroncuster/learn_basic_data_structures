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
