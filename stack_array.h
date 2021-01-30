#include <bits/stdc++.h>
using namespace std;

template <class T>
class myStackArray {
    private:
        int size, top;
        T *array;
        void clearStack();
    public:
        myStackArray(){
            size =10;
            top =-1;
            array = new T[size];
        }
        myStackArray(int size);
        ~myStackArray();
        
        bool isEmpty();
        bool isFull();
        void push(T value);
        T pop();
        T getTop();
        int getSize();
        void display();
};


    template <class T>
    myStackArray<T>::myStackArray(int size){
            this->size = size;
            top = -1;
            array = new T[this->size];
    }

    template<class T>
    myStackArray<T>::~myStackArray(){
        clearStack();
    }

    template <class T>
    void myStackArray<T>::clearStack(){
        
        while (top > -1)
            --top;
    }

    template <class T>
    bool myStackArray<T>::isEmpty(){
            return top == -1;
    }

    template <class T>
    bool myStackArray<T>::isFull(){
        return top == size-1;
    }

    template <class T>
    void myStackArray<T>::push(T value){
        
        if( isFull() ){
            cout << "Stack Overflow!\n";
            return;
        }

        array[++top] = value;
    }

    template <class T>
    T myStackArray<T>::pop(){
        
        if(isEmpty()){
            cout << "Stack Underflow!\n";
            T empty;
            return empty;
        }

        return array[top--];
    }

    template <class T>
    T myStackArray<T>::getTop(){

        if (isEmpty()){
            common::emptyStackMSG();
            T empty;
            return empty;
        }

        return array[top];
    }

    template <class T> 
    int myStackArray<T>::getSize(){
        return top+1;
    }

    template <class T>
    void myStackArray<T>::display(){

        if(isEmpty()){
            cout << "Empty Stack!\n";
            return;
        }    

        for(int i=top; i >= 0; i--)
            cout << array[i] << " ";
        cout <<"\n";
    }
