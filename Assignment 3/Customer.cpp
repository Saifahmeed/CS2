/*Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Person.h"
#include "Customer.h"
#include "Queue.h"
#include "Mechanic.h"
using namespace std;

Customer::Customer() {}

Customer::Customer(string name, int id, int age, int mechanicID, Appointment appointment)
    : Person(name, id, age), mechanicID(mechanicID), appointment(appointment) {}

Customer::~Customer() {}

void Customer::setMechanicID(int mechanicID) {
    this->mechanicID = mechanicID;
}

void Customer::setAppointment(Appointment appointment) {
    this->appointment = appointment;
}

int Customer::getMechanicID() const {
    return mechanicID;
}

Appointment Customer::getAppointment() const {
    return appointment;
}

bool Customer::operator<(const Customer& other) const {
    if (appointment.hours == other.appointment.hours) {
        return appointment.mins < other.appointment.mins;
    }
    return appointment.hours < other.appointment.hours;
}

bool Customer::operator>(const Customer& other) const {
    if (appointment.hours == other.appointment.hours) {
        return appointment.mins > other.appointment.mins;
    }
    return appointment.hours > other.appointment.hours;
}

bool Customer::operator==(const Customer& other) const {
    return (appointment.hours == other.appointment.hours) && (appointment.mins == other.appointment.mins);
}

void Customer::printInfo() const {
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Mechanic ID: " << mechanicID << endl;
    cout << "Appointment time: " << appointment.hours << ":" << appointment.mins << endl;
}
