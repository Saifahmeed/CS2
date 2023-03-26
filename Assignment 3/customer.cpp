#include <iostream>
#include <string>
#include "customer.h"


void customer::setMechanicID(int x){ // setter
  MechanicID = x;}

void customer::setappointment(appointment appointment_){ // setter
  Appointment.hours = appointment_.hours;
  Appointment.mins = appointment_.mins;
  ;}

int customer::getMechanicID(){ // getter
  return MechanicID;}

appointment customer::getappointment(){// getter
  return Appointment;}
  
void customer::print(){ // print function
  cout << "\n"<<"Mr/Mrs. "<< name <<" has appointment with ";
  }

bool customer::operator == (const customer &x)// overloading the assignment == operator
{
	return(x.Appointment.hours == Appointment.hours)&&(x.Appointment.mins == Appointment.mins);
	
}
bool customer::operator > (const customer &x)//  overloading the > operator
{
	return(Appointment.hours > x.Appointment.hours)||((Appointment.hours == x.Appointment.hours)&&(Appointment.mins > x.Appointment.mins));
	
}
bool customer::operator < (const customer &x)//  overloading the < operator
{
	return(Appointment.hours < x.Appointment.hours)||((Appointment.hours == x.Appointment.hours)&&(Appointment.mins < x.Appointment.mins));
	
}


