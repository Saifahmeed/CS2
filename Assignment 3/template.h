#ifndef TEMPLATE
#define TEMPLATE
template <class T>

class queue
{
    T *arr;         // array of queue members
    int maxsize = 15;   // maxsize of the queue
    int front;      // front is the  first element  
    int rear;       // rear is the last element
    int count;      //  size of the queue
 
public:
    queue(int s=15);
    int size();
    T peek();
    void pop();
    void push(T);
    bool isEmpty();
    bool isFull();
};
#endif