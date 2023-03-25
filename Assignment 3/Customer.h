#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <queue>
#include "Person.h"
#include "Queue.h"
#include "Mechanic.h"
using namespace std;

class Customer : public Person {
public:
    Customer();
    Customer(std::string name, int id, int age, int mechanicID, Appointment appointment);
    ~Customer();
    void setMechanicID(int mechanicID);
    void setAppointment(Appointment appointment);
    int getMechanicID() const;
    Appointment getAppointment() const;
    bool operator<(const Customer& other) const;
    bool operator>(const Customer& other) const;
    bool operator==(const Customer& other) const;
    virtual void printInfo() const;

private:
    int mechanicID;
    Appointment appointment;
    string name;
    int time;
    Mechanic* mechanic;
};

#endif
