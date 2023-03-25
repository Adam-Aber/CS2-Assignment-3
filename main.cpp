//Adam Aberbach 900225980

#include <iostream>
#include <fstream>
#include <string>
#include "QueueTemp.h"
#include "Mechanic.h"
#include "Customer.h"
using namespace std;

int main() {

    ifstream mechanicsInput("C:\\Users\\Adam\\CLionProjects\\Car shop\\mechanics.txt"); // open the two files
    ifstream customersInput("C:\\Users\\Adam\\CLionProjects\\Car shop\\customers.txt");

    string name, age, id, counter, hours, minutes;
    int mechSize = 3, custSize = 4; // a set number of customers and mechanics in this program
    Customer earliest;
    Customer::Appointment appointment;
    QueueTemp<Customer> CustomerQueue(custSize);

    Mechanic* mechanics = new Mechanic[mechSize]; // arrays of customers and mechanics
    Customer* customers = new Customer[custSize];

    for (int i = 0; i < mechSize; i++) {
        getline(mechanicsInput, name); // reading from files
        getline(mechanicsInput, age);
        getline(mechanicsInput, id);
        getline(mechanicsInput, counter);

        mechanics[i] = Mechanic(name, stoi(age), stoi(id), stoi(counter)); // adding mechanics to the array

        for (int j = 0; j < stoi(counter); j++) {
            getline(mechanicsInput, hours);
            getline(mechanicsInput, minutes);

            appointment.hours = stoi(hours);
            appointment.mins = stoi(minutes);
            (mechanics + j)->setAppointments(appointment, j); // setting the existing appointments
        }
    }

    for (int i = 0; i < custSize; i++) {
        getline(customersInput, name); // reading the customers data
        getline(customersInput, age);
        getline(customersInput, id);
        getline(customersInput, hours);
        getline(customersInput, minutes);

        appointment.hours = stoi(hours);
        appointment.mins = stoi(minutes); // setting the customers in the array
        (customers + i)->setAppointment(appointment)->setName(name)->setAge(stoi(age))->setId(stoi(id));
    }

    for (int i = 0; i < custSize - 1; i++) { // ordering the customers according to the time of their appointments
        earliest = *(customers + i);
        for (int j = i + 1; j < custSize; j++) {
            if (earliest > *(customers + j)) {
                *(customers + i) = *(customers + j);
                *(customers + j) = earliest;
            }
        }
    }

    for (int i = 0; i < custSize; i++) { // checking if mechanic is available then assigning him to customer
        for (int j = 0; j < mechSize; j++) {
            if ( (mechanics + j)->isAvailable((customers + i)->getAppointment()) ) {
                (customers + i)->setMechanicId((mechanics + j)->getId());
                CustomerQueue.Push(*(customers+i)); // adding customers to queue in order
                (mechanics + j)->setAppointments((customers + i)->getAppointment(), (mechanics + j)->getCounter());
                cout << "Mr. " << (customers + i)->getName() << " has an appointment at ";
                cout << to_string(appointment.hours) << ":" << to_string(appointment.mins);
                cout << " with " << (mechanics + j)->getName() << endl;
                break; // exit if one mechanic found available
            }
            if (j == mechSize - 1) cout << "No mechanics available." << endl; // when no mechanic is available
        }
    }

    return 0;
}
