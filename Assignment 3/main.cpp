/*Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Person.h"
#include "Customer.h"
#include "Queue.h"
#include "Mechanic.h"
using namespace std;

int main() {
    int numMechanics, numCustomers;
    cout << "Enter the number of mechanics: ";
    cin >> numMechanics;

    Mechanic *mechanics = new Mechanic[numMechanics];
    for (int i = 0; i < numMechanics; i++) {
        cout << "Enter the name of mechanic " << i+1 << ": ";
        string name;
        cin >> name;
        mechanics[i].setName(name);
    }

    cout << "Enter the number of customers: ";
    cin >> numCustomers;
    Customer *customers = new Customer[numCustomers];
    for (int i = 0; i < numCustomers; i++) {
        cout << "Enter the name of customer " << i+1 << ": ";
        string name;
        cin >> name;

        int hour, minute;
        char separator;
        cout << "Enter the appointment time for " << name << " (hh:mm): ";
        cin >> hour >> separator >> minute;

        customers[i].setName(name);
        customers[i].setAppointment(hour, minute);
    }

    int mechanicIndex = 0;
    for (int i = 0; i < numCustomers; i++) {
        Customer customer = customers[i];
        bool assigned = false;
        while (!assigned) {
            if (mechanics[mechanicIndex].isAvailable(customer.getAppointment())) {
                mechanics[mechanicIndex].assignCustomer(customer);
                assigned = true;
            }
            else {
                mechanicIndex = (mechanicIndex + 1) % numMechanics;
            }
        }
    }

    Queue<Customer> customerQueue;
    for (int i = 0; i < numCustomers; i++) {
        customerQueue.enqueue(customers[i]);
    }

    while (!customerQueue.isEmpty()) {
        Customer customer = customerQueue.dequeue();
        Mechanic assignedMechanic = customer.getAssignedMechanic();
        cout << "Mr./Mrs. " << customer.getName() << " should be assigned to " << assignedMechanic.getName() << " at " << customer.getAppointment().toString() << endl;
    }

    delete[] mechanics;
    delete[] customers;

    return 0;
}
