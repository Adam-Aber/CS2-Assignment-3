//
// Created by Adam on 3/22/2023.
//
#include "Person.h"
#include <string>
using namespace std;

#ifndef UNTITLED_MECHANIC_H
#define UNTITLED_MECHANIC_H


class Mechanic: public Person {
private:
    int counter; //number of appointments the mechanic has for the day
    Appointment *appointments; // the times the mechanic is booked

public:
    Mechanic(const string&, const int&a, const int&i, const int &c);
    Mechanic();
    ~Mechanic();
    bool isAvailable(const Appointment&);

    void setCounter(const int&);
    void setAppointments(Appointment, int);

    int getCounter() const;
    Appointment* getAppointments() const;
};


#endif //UNTITLED_MECHANIC_H
