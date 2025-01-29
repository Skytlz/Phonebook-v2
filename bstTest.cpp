//
// Created by skytl on 1/26/25.
//

#include "bst.hpp"
#include "catch.hpp"

TEST_CASE("BST Constructor", "[BST]") {
    const BST bst;
    const std::string message = "END OF TREE";
    std::ostringstream os;
    os << bst;
    REQUIRE(os.str() == message);
    REQUIRE(bst.height() == 0);
    REQUIRE(bst.duplicates());

    const BST bst2(false);
    os.str(std::string());
    os << bst2;
    REQUIRE(os.str() == message);
    REQUIRE(bst2.height() == 0);
    REQUIRE_FALSE(bst2.duplicates());
}

TEST_CASE("BST Insert", "[BST]") {
    BST bst;
    Person person;
    person.firstname = "John";
    person.lastname = "Doe";
    person.phone = "12345";

    std::ostringstream personstream;
    personstream << person;
    std::string personos = personstream.str() + "\nEND OF TREE";


    REQUIRE(bst.duplicates());
    REQUIRE(bst.insertPerson(person));
    REQUIRE(bst.height() == 1);
    std::ostringstream bststream;
    bststream << bst;
    REQUIRE(bststream.str() == personos);

    Person person2;
    person2.firstname = "Jane";
    person2.lastname = "Doe";
    person2.phone = "12345";
    REQUIRE(bst.insertPerson(person2));
    REQUIRE(bst.height() == 2);
    personstream.str(std::string());
    personstream << person2 << std::endl << person << std::endl << "END OF TREE";
    bststream.str(std::string());
    bststream << bst;
    REQUIRE(bststream.str() == personstream.str());

    Person person3;
    person3.firstname = "Michael";
    person3.lastname = "Xantham";
    person3.phone = "12345";
    REQUIRE(bst.insertPerson(person3));
    REQUIRE(bst.height() == 2);
    personstream.str(std::string());
    personstream << person2 << std::endl << person << std::endl << person3 << std::endl << "END OF TREE";
    bststream.str(std::string());
    bststream << bst;
    REQUIRE(bststream.str() == personstream.str());
}

TEST_CASE("BST Delete", "[BST]") {
    BST bst;
    Person person;
    person.firstname = "John";
    person.lastname = "Doe";
    person.phone = "12345";

    Person person2;
    person2.firstname = "Jane";
    person2.lastname = "Doe";
    person2.phone = "12345";

    Person person3;
    person3.firstname = "Michael";
    person3.lastname = "Xantham";
    person3.phone = "12345";

    REQUIRE(bst.insertPerson(person));
    REQUIRE(bst.insertPerson(person2));
    REQUIRE(bst.insertPerson(person3));

    REQUIRE(bst.height() == 2);

    std::ostringstream personstream;
    std::ostringstream bststream;

    personstream.str(std::string());
    personstream << person2 << std::endl << person << std::endl << person3 << std::endl << "END OF TREE";
    bststream.str(std::string());
    bststream << bst;
    REQUIRE(bststream.str() == personstream.str());

    REQUIRE(bst.deletePerson(person));
    REQUIRE(bst.deletePerson(person2));
    REQUIRE(bst.deletePerson(person3));
}