//
// Created by skytl on 1/21/25.
//
#include "person.h"

#include <ostream>
#include <tuple>

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Name: " << person.lastname << ", " << person.firstname << std::endl;
    os << "Phone number: " << person.phone << std::endl;
    return os;
}

bool operator==(const Person& person1, const Person& person2) {
   return std::tie(person1.firstname, person1.lastname, person1.phone) == std::tie(person2.firstname, person2.lastname, person2.phone);
}

bool operator!=(const Person& person1, const Person& person2) {
    return !(person1 == person2);
}

bool operator<(const Person& person1, const Person& person2) {
    return std::tie(person1.firstname, person1.lastname, person1.phone) < std::tie(person2.firstname, person2.lastname, person2.phone);
}

bool operator>(const Person& person1, const Person& person2) {
    return person2 < person1;
}

bool operator<=(const Person& person1, const Person& person2) {
    return !(person2 < person1);
}

bool operator>=(const Person& person1, const Person& person2) {
    return !(person1 < person2);
}

