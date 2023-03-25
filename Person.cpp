//
// Created by Adam on 3/22/2023.
//
#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(const string &n, const int &i, const int &a) {
    setName(n);
    setAge(a);
    setId(i);
}

Person* Person::setName(const string &n) {
    name = n;
    return this;
}

Person* Person::setId(const int &i) {
    id = i;
    return this;
}

Person* Person::setAge(const int &a) {
    age = a;
    return this;
}

string Person::getName() const {
    return name;
}

int Person::getId() const{
    return id;
}

int Person::getAge() const {
    return age;
}

void Person::printinfo() const {
    cout << "Name: " << getName() << endl;
    cout << "Id: " << getId() << endl;
    cout << "Age: " << getAge() << endl;
}




