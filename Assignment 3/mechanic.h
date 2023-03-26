#ifndef MECHANIC
#define MECHANIC
#include <iostream>
#include "person.h"

class mechanic: public person { //  inheriting from class person
  private: int counter; // declaring  counter
  appointment apps[24]; //declaring an array with maxiumum of 24 appointments(as for 24 hours)

  public: mechanic(); // constructor
  void setappointments(appointment appoinment_); // setter

  bool isavailable(appointment appoinment_);

  int getcounter(); // getter

  appointment getappointment();
  void print(); //  void print method
};

#endif