//
// Created by Adam on 3/22/2023.
//
#include "Person.h"
using namespace std;

#ifndef UNTITLED_CUSTOMER_H
#define UNTITLED_CUSTOMER_H


class Customer: public Person {
private:
    double mechanicID; // ID of the mechanic assigned to their case
    Appointment appointment; // customer’s appointment with the mechanic.


public:
    void setMechanicId(const double &i);
    Customer* setAppointment(const Appointment&);

    double getMechanicId() const;
    Appointment getAppointment() const;

    bool operator == (const Customer &c) const;
    bool operator < (const Customer &c) const;
    bool operator > (const Customer &c) const;

};


#endif //UNTITLED_CUSTOMER_H
