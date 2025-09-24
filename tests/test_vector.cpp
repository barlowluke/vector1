// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.hpp"
#include <stdexcept>

TEST_CASE("Default constructor creates empty vector") {
    dsa::Vector<int> v;
    bool ok{true};
    REQUIRE(ok);
}

