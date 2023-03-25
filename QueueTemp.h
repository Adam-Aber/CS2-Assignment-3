//
// Created by Adam on 3/23/2023.
//
#include "Customer.h"
using namespace std;
#ifndef UNTITLED_QUEUETEMP_H
#define UNTITLED_QUEUETEMP_H

template <class T> // template class queue
class QueueTemp {
private:
    int  size, front, counter, rear;
    T* values;
public:

    QueueTemp(const int& s) {
        values = new T[s];
        counter = 0;
        size	= s;
        rear = -1;
        front =	0;
    }

    ~QueueTemp() {
        delete [] values;
    }

    bool IsEmpty() {
        if (counter)
            return false;
        else
            return true;
    }

    bool IsFull() {
        if (counter < size)
            return false;
        else
            return true;
    }

    bool Push(Customer x) {
        if (IsFull()) {
            cout << "The queue is full." << endl;
            return false;
        }
        else {
            rear = (rear + 1) % size;
            values[rear] = x;
            counter++;
            return true;
        }
    }

    bool Pop(Customer & x) {
        if (IsEmpty()) {
            cout << "The queue is empty." << endl;
            return false;
        }
        else {
            x = values[front];
            front = (front + 1) % size;
            counter--;
            return true;
        }
    }
};



#endif //UNTITLED_QUEUETEMP_H
