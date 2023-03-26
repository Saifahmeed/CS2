//Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535

#include <iostream>
#include "person.h"
#include "person.cpp"
#include "mechanic.h"
#include "mechanic.cpp"
#include "customer.h"
#include "customer.cpp"
#include "template.h"
#include "template.cpp"
#include <string>
#include <fstream>

//  Returning the mechanic name by get_id
string Name_ID(mechanic array[4], int x) { 
  for (int i = 0; i < 4; i++) { // 4 is the size of the mechanic 
    if (x == array[i].get_id())
      return array[i].get_name();
  }
}
//  Sorting the customers in an ascending way using their appoinment timing 
void sor(customer customers[]) { 
  for (int i = 0; i < 14; i++) {
    for (int j = i + 1; j < 15; j++) {
      if (customers[i] > customers[j]) {
        swap(customers[i], customers[j]);
      }
    }

  }

}
int main() {
  string Name;
  int Age, Id;
  queue < customer > sort_;
  mechanic mechanics[4]; //let 4 mechanics 
  customer customers[15]; // Let 15 customers 
  ifstream file1, file2;
  file1.open("Mechanic.txt"); // Opening the  text files(the bonus question)
  file2.open("Customer.txt");

  int i = 0;
  while (!file1.eof()) {
    file1 >> Name >> Age >> Id;
    mechanics[i].set_name(Name);
    mechanics[i].set_age(Age);
    mechanics[i].set_id(Id);
    i++;
  }
  int hours, mins, d = 0;
  appointment _appointment;
  while (!file2.eof()) {
    appointment say1;
    say1.hours = 0;
    say1.mins = 0;
    file2 >> Name >> Age >> hours >> mins;
    _appointment.hours = hours;
    _appointment.mins = mins;
    customers[d].set_name(Name);
    customers[d].set_age(Age);
    int lm = 0;
    for (int size_ = (d) % 4; size_ < 4; size_++) { // here we assign each customer to the mechanic in the order the mechanics are stored
      if (mechanics[size_].isavailable(_appointment)) {
        customers[d].setappointment(_appointment);
        mechanics[size_].setappointments(_appointment);
        customers[d].print();
        mechanics[size_].print();
        customers[d].setMechanicID(mechanics[size_].get_id());

        cout << _appointment.hours << ":" << _appointment.mins;
        lm++;
        size_ = 4;

      }
    }
    if (lm == 0) {
      cout << " Appointment for " << customers[d].get_name() << " was cancelled."<< endl;
      customers[d].setMechanicID(0);
      customers[d].setappointment(say1);
    }
    d++;
  };

  cout << "After sorting: "<< endl;
  sor(customers);
  for (int j = 0; j < 15; j++) {
    sort_.push(customers[j]);
  }
  for (int j = 0; j < 15; j++) {
    sort_.peek();

    if (sort_.peek().getMechanicID() == 0) {
      sort_.peek().print();
      cout << "no mechanic";
    } else {
      sort_.peek().print();
      cout << Name_ID(mechanics, sort_.peek().getMechanicID()) << " " << sort_.peek().getappointment().hours << ":" << sort_.peek().getappointment().mins;
    }
    sort_.pop();
    
  }
  file1.close();
  file2.close();
  return 0;
}