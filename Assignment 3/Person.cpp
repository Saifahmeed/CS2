#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Person.h"
#include "Customer.h"
#include "Queue.h"
#include "Mechanic.h"
using namespace std;

Person::Person() {}

Person::Person(string name, int id, int age)
    : name(name), id(id), age(age) {}

Person::~Person() {}

void Person::setName(string name) {
    this->name = name;
}

void Person::setID(int id) {
    this->id = id;
}

void Person::setAge(int age) {
    this->age = age;
}

string Person::getName() const {
    return name;
}

int Person::getID() const {
    return id;
}

int Person::getAge() const {
    return age;
}