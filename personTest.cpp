//
// Created by skytl on 1/23/25.
//

#include "person.h"
#include "catch.hpp"

TEST_CASE("Person", "[Person]") {
    Person person;
    person.firstname = "John";
    person.lastname = "Doe";
    person.phone = "1234567";

    REQUIRE(person.firstname == "John");
    REQUIRE(person.lastname == "Doe");
    REQUIRE(person.phone == "1234567");
}