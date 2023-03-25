//
// Created by Adam on 3/22/2023.

#include <string>
using namespace std;

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H


class Person {
private:
    string name;
    int id;
    int age;

public:

    Person(const string &n = "", const int &i = 0, const int &a = 0);

    Person* setName(const string &n);
    Person* setId(const int &i);
    Person* setAge(const int &a);

    string getName() const;
    int getId() const;
    int getAge() const;

    void printinfo() const;

    struct Appointment {
        int hours;
        int mins;
    };
};


#endif //UNTITLED_PERSON_H
