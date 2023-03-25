
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Person.h"
#include "Customer.h"
#include "Queue.h"
#include "Mechanic.h"
using namespace std;


Mechanic::Mechanic() {}

Mechanic::Mechanic(string name, int id, int age)
    : Person(name, id, age), counter(0) {}

Mechanic::~Mechanic() {}

bool Mechanic::isAvailable(Appointment appointment) const {
    for (int i = 0; i < counter; i++) {
        if (appointments[i].hours == appointment.hours && appointments[i].mins == appointment.mins) {
            return false;
        }
    }
    return true;
}

void Mechanic::setAppointment(Appointment appointment) {
    appointments[counter++] = appointment;
}

int Mechanic::getCounter() const {
    return counter;
}

void Mechanic::printInfo() const {
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Appointments: " << endl;
    for (int i = 0; i < counter; i++) {
        cout << appointments[i].hours << ":" << appointments[i].mins << endl;
    }
}
