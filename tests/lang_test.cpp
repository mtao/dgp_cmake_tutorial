#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "localization.hpp"



TEST_CASE( "Languages are included", LANG_TEST_LANG )
{
    REQUIRE( get_hello( LANG_TEST_LANG ).size() > 0 );
}
