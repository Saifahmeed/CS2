#include "template.h"
#include <iostream>
using namespace std;
template <class T>
queue<T>::queue(int s)
{
    arr = new T[s];// Making a dynamic array of size s
    maxsize = s;
    front = 0;
    rear = -1; // default
    count = 0;
}

template <class T>
void queue<T>::push(T n)
{
    if (isFull())//  checking if it is full or not to  push 
    {
        cout << "It is full"<<endl;
    }
 	else
 	{
    rear = (rear + 1) % maxsize;
    arr[rear] = n;
    count++;
	}
}
template <class T>
T queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "It is empty"<< endl;
    }
    else
    	return arr[front];
}
template <class T>
void queue<T>::pop()
{
    if (isEmpty())// we check whther we can pop or not
    {
        cout << "It is empty"<< endl;
    }
    else
 	{
    front = (front + 1) % maxsize;
    count--;
	}
}
template <class T>
int queue<T>::size() {
    return count;
}
template <class T>
bool queue<T>::isEmpty() {
    return (size() == 0);
}
template <class T>
bool queue<T>::isFull() {
    return (size() == maxsize);
}
