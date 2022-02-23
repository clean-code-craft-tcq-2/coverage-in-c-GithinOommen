#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to low limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to high limits") {
  REQUIRE(inferBreach(50, 20, 30) == TOO_HIGH);
}
TEST_CASE("infers the breach according to normal limits") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
TEST_CASE("classify the Temperature Breach according to LOW limits") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-1) == TOO_LOW);
}
TEST_CASE("classify the Temperature Breach according to HIGH limits") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-1) == TOO_HIGH);
}
TEST_CASE("classify the Temperature Breach according to LOW limits") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-1) == NORMAL);
}
