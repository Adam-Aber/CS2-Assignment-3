//
// Created by Adam on 3/22/2023.
//
#include <string>
#include "Mechanic.h"
using namespace std;

bool Mechanic::isAvailable(const Appointment&a) {
    bool available = true;
    for (int i = 0; i < counter; i++) { // checking if time is the same
        if ( (appointments + i)->hours == a.hours && (appointments + i)->mins == a.mins ) {
            available = false;
            break;
        }
    }
    return available;
}
// setters, getters, constructor and destructor

void Mechanic::setCounter(const int &c) {
    counter = c;
}

void Mechanic::setAppointments(Appointment a, int i) {
    *(appointments + i) = a;
    counter++;
}

int Mechanic::getCounter() const {
    return counter;
}

Person::Appointment* Mechanic::getAppointments() const {
    return appointments;
}

Mechanic::Mechanic(const string& n, const int& a, const int& i, const int& c) : Person(n, i, a) {
    setCounter(c);
    appointments = new Appointment[10];
}

Mechanic::~Mechanic() {
    delete [] appointments;
}

Mechanic::Mechanic() = default;
