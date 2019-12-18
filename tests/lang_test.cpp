#include <catch2/catch.hpp>
#include "localization.hpp"



TEST_CASE( "lang_test_" LANG_TEST_LANG, LANG_TEST_LANG )
{
    REQUIRE( get_hello( LANG_TEST_LANG ).size() > 0 );
}
