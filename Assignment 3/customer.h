
#ifndef CUSTOMER
#define CUSTOMER
#include <iostream>

#include <string>

#include "person.h"

using namespace std;

class customer: public person {

  private:

    int MechanicID; // Indicating the ID of the mechanic assigned to them.
    appointment Appointment;

  public:

    void setMechanicID(int x);// setter

  // overloading operators
  bool operator < (const customer & x);
  bool operator > (const customer & x);
  bool operator == (const customer & x);

  void setappointment(appointment appointment_);

  int getMechanicID(); // getter

  appointment getappointment(); // getter

  void print();// print function
};

#endif