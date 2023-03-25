//
// Created by Adam on 3/22/2023.
//

#include "Customer.h"
using namespace std;

void Customer::setMechanicId(const double &i) {
    mechanicID = i;
}

Customer* Customer::setAppointment(const Appointment& a) {
    appointment.hours = a.hours;
    appointment.mins = a.mins;
    return this;
}

double Customer::getMechanicId() const {
    return mechanicID;
}

Customer::Appointment Customer::getAppointment() const {
    return appointment;
}

bool Customer::operator==(const Customer &c) const {    // check if time is the same
    return ((getAppointment().hours == c.getAppointment().hours) && (getAppointment().mins == c.getAppointment().mins));
}

bool Customer::operator < (const Customer &c) const { // check if time is less
    if (getAppointment().hours < c.getAppointment().hours)
        return true;
    else if (getAppointment().hours == c.getAppointment().hours)
        return (getAppointment().mins < c.getAppointment().mins);
    else
        return false;
}

bool Customer::operator > (const Customer &c) const {   // check if time is more
    if (getAppointment().hours > c.getAppointment().hours)
        return true;
    else if (getAppointment().hours == c.getAppointment().hours)
        return (getAppointment().mins > c.getAppointment().mins);
    else
        return false;
}
