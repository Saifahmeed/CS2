/*Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535*/
#include <iostream>
#include "linked_list.h"
#include <vector>
using namespace std;

// Function to insert secondValue after each occurrence of firstValue in the vector
void insertAfter(vector<int>& v, int firstValue, int secondValue) {
for (int i = 0; i < v.size(); i++) {
if (v[i] == firstValue) {
v.insert(v.begin() + i + 1, secondValue);
i++; // Skip the inserted n
}
}
}

// Constructor
LinkedList::LinkedList() {
head = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
Node* now = head;
while (now != nullptr) {
Node* neww = now;
now = now->next;
delete neww;
}
}

// Function to add a node to the linked list
void LinkedList::addNode(int n, int d) {
// Create a new node
Node* newNode = new Node;
newNode->n = n;
newNode->d = d;
newNode->next = nullptr;
// If the linked list is empty, set the new node as the head
if (head == nullptr) {
    head = newNode;
    return;
}

// Traverse the linked list to find the last node
Node* now = head;
while (now->next != nullptr) {
    now = now->next;
}

// Add the new node to the end of the linked list
now->next = newNode;
}

// Function to remove a node from the linked list
void LinkedList::removeNode(int n) {
// If the linked list is empty, return
if (head == nullptr) {
return;
}
// If the head node is to be removed
if (head->n == n) {
    Node* neww = head;
    head = head->next;
    delete neww;
    return;
}

// Traverse the linked list to find the node to be removed
Node* now = head;
while (now->next != nullptr) {
    if (now->next->n == n) {
        Node* neww = now->next;
        now->next = neww->next;
        delete neww;
        return;
    }
    now = now->next;
}
}

// Function to print all elements of the linked list
void LinkedList::printList() {
Node* now = head;
while (now != nullptr) {
cout << now->n << " (" << now->d << ")" << endl;
now = now->next;
}
}

// Function to create a linked list based on the vector's elements
LinkedList LinkedList::createList(vector<int> v) {
    LinkedList list;
    for (int i = 0; i < v.size(); i++) {
        int n = v[i];
        Node* now = list.head;
        while (now != nullptr) {
            if (now->n == n) {
                now->d++;
                break;
            }
            now = now->next;
        }
        if (now == nullptr) {
            list.addNode(n, 1);
        }
    }
    return list;
}

// Function to return the sum of all nodes
int LinkedList::getSum() {
int sum = 0;
Node* now = head;
while (now != nullptr) {
sum += now->n;
now = now->next;
}
return sum;
}


int main() {
// Take input from the user
int n;
cout << "Enter the number of integers: ";
cin >> n;
vector<int> v(n);
cout << "Enter " << n << " integers:" << endl;
for (int i = 0; i < n; i++) {
    cin >> v[i];
}

// Take input for first number and second number
int firstValue, secondValue;
cout << "Enter first value: ";
cin >> firstValue;
cout << "Enter second value: ";
cin >> secondValue;

// Insert second value after each occurrence of first value in the vector
insertAfter(v, firstValue, secondValue);

// Print the modified vector
cout << "Modified vector: ";
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
cout << endl;

// Create a linked list based on the vector's elements
LinkedList list = list.createList(v);

// Print the elements of the linked list
cout << "Linked list: " << endl;
list.printList();

// Remove a node from the linked list
int removen;
cout << "Enter a n to remove from the linked list: ";
cin >> removen;
list.removeNode(removen);

// Print the updated linked list
cout << "Updated linked list: " << endl;
list.printList();

// Get the sum of all nodes in the linked list
int sum = list.getSum();
cout << "Sum of all nodes: " << sum << endl;

return 0;
}