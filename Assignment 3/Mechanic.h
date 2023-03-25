#ifndef MECHANIC_H
#define MECHANIC_H

#include <iostream>
#include <string>
#include <queue>
#include "Person.h"
#include "Customer.h"
#include "Queue.h"

using namespace std;
const int MAX_APPOINTMENTS = 10;

class Mechanic : public Person {
public:
    Mechanic();
    Mechanic(string name, int id, int age);
    ~Mechanic();
    bool isAvailable(Appointment appointment) const;
    void setAppointment(Appointment appointment);
    int getCounter() const;
    virtual void printInfo() const;

private:
    int counter;
    Appointment appointments[MAX_APPOINTMENTS];
};

#endif
