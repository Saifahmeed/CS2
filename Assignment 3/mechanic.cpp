
#include "mechanic.h"
mechanic:: mechanic(){
  counter = 0;
}

void mechanic::setappointments(appointment appoinment_){
  apps[counter].hours = appoinment_.hours;
  apps[counter].mins = appoinment_.mins;//we set the appointment then we increment the counter to move to the next 
  counter++;

}
bool mechanic::isavailable(appointment appoinment_){ //incomplete
int c=0;
  for (int i = 0; i < counter+1; i++)
  {
    if(apps[i].hours==appoinment_.hours&&apps[i].mins==appoinment_.mins){
      c++;
      i=counter;}
  }
  if(c==0){return 1;}
  else{
    return 0;}// we check if the desired time is already booked for this mechanic
}
appointment mechanic::getappointment(){
  return apps[counter];// we return the latest appointment
}

int mechanic::getcounter(){
  return counter;}

void mechanic::print(){
  cout << "Mr. "<< name<<" on ";
}


