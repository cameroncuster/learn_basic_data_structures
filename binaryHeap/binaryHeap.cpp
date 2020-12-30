#include "..//catch.hpp"
#include "binaryHeap.h"

TEST_CASE( "constructor" )
{
    binaryHeap heap;

    REQUIRE( heap.isEmpty( ) == true );
}