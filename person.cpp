//
// Created by skytl on 1/21/25.
//
#include "person.h"

#include <ostream>

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Name: " << person.lastname << ", " << person.firstname << std::endl;
    os << "Phone number: " << person.phone << std::endl;
    os << "Email: " << person.email << std::endl;
    os << "Address: " << person.address << std::endl;
    os << "Phone number: " << person.phone << std::endl;
    os << "Birthday: " << person.birthday << std::endl;
    os << "Occupation: " << person.occupation << std::endl;
    os << std::endl;
    return os;
}

bool operator==(const Person& person1, const Person& person2) {
    return person1.firstname == person2.firstname
        && person1.lastname == person2.lastname
        && person1.phone == person2.phone
        && person1.email == person2.email
        && person1.address == person2.address
        && person1.birthday == person2.birthday
        && person1.occupation == person2.occupation;
}

bool operator!=(const Person& person1, const Person& person2) {
    return person1.firstname != person2.firstname
           || person1.lastname != person2.lastname
           || person1.phone != person2.phone
           || person1.email != person2.email
           || person1.address != person2.address
           || person1.birthday != person2.birthday
           || person1.occupation != person2.occupation;
}

bool operator<(const Person& person1, const Person& person2) {
    return person1.firstname < person2.firstname
    || person1.lastname < person2.lastname
    || person1.phone < person2.phone
    || person1.email < person2.email
    || person1.address < person2.address
    || person1.birthday < person2.birthday
    || person1.occupation < person2.occupation;
}

bool operator>(const Person& person1, const Person& person2) {
    return person1.firstname > person2.firstname
    || person1.lastname > person2.lastname
    || person1.phone > person2.phone
    || person1.email > person2.email
    || person1.address > person2.address
    || person1.birthday > person2.birthday
    || person1.occupation > person2.occupation;
}

bool operator<=(const Person& person1, const Person& person2) {
    return person1.firstname <= person2.firstname
    || person1.lastname <= person2.lastname
    || person1.phone <= person2.phone
    || person1.email <= person2.email
    || person1.address <= person2.address
    || person1.birthday <= person2.birthday
    || person1.occupation <= person2.occupation;
}

bool operator>=(const Person& person1, const Person& person2) {
    return person1.firstname >= person2.firstname
    || person1.lastname >= person2.lastname
    || person1.phone >= person2.phone
    || person1.email >= person2.email
    || person1.address >= person2.address
    || person1.birthday >= person2.birthday
    || person1.occupation >= person2.occupation;
}

