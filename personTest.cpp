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

TEST_CASE("Person Compare", "[Person]") {
    Person person1;
    person1.firstname = "John";
    person1.lastname = "Doe";
    person1.phone = "1234567";

    Person person2;
    person2.firstname = "John";
    person2.lastname = "Doe";
    person2.phone = "1234567";

    REQUIRE(person1 == person2);

    Person person3;
    person3.firstname = "Jane";
    person3.lastname = "Doe";
    person3.phone = "1234567";

    REQUIRE(person3 != person1);
    REQUIRE(person3 <= person1);
    REQUIRE(person3 < person1);
    REQUIRE(person1 >= person3);
    REQUIRE(person1 > person3);

    REQUIRE(!(person3 > person1));

    person3.firstname = "Michael";
    REQUIRE(person3 != person1);
    REQUIRE(person3 >= person1);
    REQUIRE(person3 > person1);
    REQUIRE(person1 <= person3);
    REQUIRE(person1 < person3);

    REQUIRE(!(person3 < person1));

    person3.firstname = "John";
    person3.lastname = "Albatross";

    REQUIRE(person3 != person1);
    REQUIRE(person3 <= person1);
    REQUIRE(person3 < person1);
    REQUIRE(person1 >= person3);
    REQUIRE(person1 > person3);

    REQUIRE(!(person3 > person1));

    person3.lastname = "Xantham";

    REQUIRE(person3 != person1);
    REQUIRE(person3 >= person1);
    REQUIRE(person3 > person1);
    REQUIRE(person1 <= person3);
    REQUIRE(person1 < person3);

    REQUIRE(!(person3 < person1));

    person3.lastname = "Doe";
    person3.phone = "987654321";

    REQUIRE(person3 != person1);
    REQUIRE(person3 >= person1);
    REQUIRE(person3 > person1);
    REQUIRE(person1 <= person3);
    REQUIRE(person1 < person3);

    REQUIRE(!(person3 < person1));
}

TEST_CASE("Person Ostream Test", "[Person]") {
    Person person;
    person.firstname = "John";
    person.lastname = "Doe";
    person.phone = "1234567";

    std::ostringstream os;
    std::string output = "Name: Doe, John\nPhone number: 1234567\n\n";
    os << person;
    REQUIRE(output == os.str());
}
