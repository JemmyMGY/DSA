#include <bits/stdc++.h>
using namespace std;

template<class T>
class myQueueArray{
private:
    int size, front, rare;
    T* array;
public:
    myQueueArray(){
        size = 10;
        front = rare = 0;
        array = new T[size];
    }
    myQueueArray(int size);
    ~myQueueArray();

    bool isEmpty();
    bool isFull();
    void enqueue(T value);
    T dequeue();
    T getFront();
    int getSize();
    void display();

};

    template<class T>
    myQueueArray<T>::myQueueArray(int size) {
        this->size = size;
        front = rare = 0;
        array = new T[size];
    }

    template<class T>
    myQueueArray<T>::~myQueueArray<T>() {
        front = rare = 0;
    }

    template<class T>
    bool myQueueArray<T>::isEmpty() {
        return front == rare ? 1 : 0;
    }

    template<class T>
    bool myQueueArray<T>::isFull() {
        return rare == size-1 ? 1 : 0;
    }

    template<class T>
    void myQueueArray<T>::enqueue(T value) {
        if (isFull()){
            if (getSize() >= size-1){
                cout << "Queue is Full!\n";
                return;
            }
            rare = -1;
        }

        if (rare+1 == front){
            cout << "Queue is Full!\n";
            return;
        }

        array[++rare] = value;
    }

    template<class T>
    T myQueueArray<T>::dequeue() {
        if (isEmpty()){
            common::emptyQueueMSG();
            T empty;
            return empty;
        }

        if(front == size-1)
            front = -1;

        return array[++front];

    }
    template<class T>
    T myQueueArray<T>::getFront() {
        if (isEmpty()) {
            common::emptyQueueMSG();
            T empty;
            return empty;
        }
        return array[front];
    }

    template<class T>
    int myQueueArray<T>::getSize() {
        if (isEmpty()) {
            common::emptyQueueMSG();
            return -1;
        }
        return abs(rare - front);
    }

    template<class T>
    void myQueueArray<T>::display() {
        if (isEmpty()) {
            common::emptyQueueMSG();
            return;
        }
        for (int i = front+1; i <= rare; ++i) {
            cout << array[i] << " ";
        }
        cout <<"\n";
    }