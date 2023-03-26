#include <iostream>

#include <string>

#include "person.h"

using namespace std;
person::person() { // default constractor using default intialziation
  name = "";
  id = 0;
  age = 0;
}

int person::get_age() { //getter age
  return age;
}

string person::get_name() { //getter name
  return name;
}

int person::get_id() { //getter ID
  return id;
}
void person::set_name(string y) { //setter name
  name = y;
}

void person::set_id(int y) { //setter ID
  id = y;
}

void person::set_age(int y) { //setter agE
  age = y;
}