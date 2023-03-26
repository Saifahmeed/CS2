#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>

using namespace std;
struct appointment {
  int hours;
  int mins;
}; // we declare the structure 
class person {
  protected: // we declare the protected variables
    string name;
  int id;
  int age;

  public: 
  person();// default constructor
  void set_name(string y);
  void set_id(int y);
  void set_age(int y);
  string get_name();
  int get_id();
  int get_age();
  virtual void print() = 0; // Making print function pure virtual so the class person be abstract.
};

#endif