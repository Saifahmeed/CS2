/*Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>

using namespace std;

// Node structure to hold the value n and its number of occurrences (d) in the vector
struct Node {
int n;
int d;
Node* next;
};


class LinkedList {
public:
// Constructor and destructor
LinkedList();
~LinkedList();
// Functions to add and remove a node
void addNode(int n, int d);
void removeNode(int n);

// Function to print all elements of the linked list
void printList();

// Function to create a linked list based on the vector's elements
LinkedList createList(vector<int> v);

// Function to return the sum of all nodes
int getSum();
private:
Node* head;
};

#endif 