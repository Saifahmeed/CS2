#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "Customer.h"
#include "Queue.h"
#include "Mechanic.h"
using namespace std;

class Person {
public:
    Person();
    Person(string name, int id, int age);
    virtual ~Person();
    void setName(string name);
    void setID(int id);
    void setAge(int age);
    string getName() const;
    int getID() const;
    int getAge() const;
    virtual void printInfo() const = 0;
    struct Appointment {
    int hours;
    int mins;
};
private:
    string name;
    int id;
    int age;
};

#endif
