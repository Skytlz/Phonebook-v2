//
// Created by skytl on 1/21/25.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

typedef struct {
    string firstname;
    string lastname;
    string email;
    string address;
    string phone;
    string birthday;
    string occupation;
} Person;

std::ostream& operator<<(std::ostream& os, const Person& person);
bool operator==(const Person& person1, const Person& person2);
bool operator!=(const Person& person1, const Person& person2);
bool operator<(const Person& person1, const Person& person2);
bool operator>(const Person& person1, const Person& person2);
bool operator<=(const Person& person1, const Person& person2);
bool operator>=(const Person& person1, const Person& person2);


#endif //PERSON_H
