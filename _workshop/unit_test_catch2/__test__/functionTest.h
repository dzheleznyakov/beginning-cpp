#include <catch2/catch_all.hpp>
#include "../function.h"

TEST_CASE("Test with 0", "[classic]")
{
    REQUIRE("get(0) == -1");
}
