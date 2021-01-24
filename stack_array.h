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
            this->size =10;
            this->top =-1;
            this->array = new T[this->size];
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
            this->top = -1;
            this->array = new T[this->size];
    }

    template<class T>
    myStackArray<T>::~myStackArray(){
        clearStack();
    }

    template <class T>
    void myStackArray<T>::clearStack(){
        
        while (this->top > -1)
            --this->top;
    }

    template <class T>
    bool myStackArray<T>::isEmpty(){
            return this->top == -1;
    }

    template <class T>
    bool myStackArray<T>::isFull(){
        return this->top == this->size-1;
    }

    template <class T>
    void myStackArray<T>::push(T value){
        
        if( isFull() ){
            cout << "Stack Overflow!\n";
            return;
        }

        this->array[++this->top] = value;
    }

    template <class T>
    T myStackArray<T>::pop(){
        
        if(isEmpty()){
            cout << "Stack Underflow!\n";
            return -1;
        }

        return this->array[this->top--];
    }

    template <class T>
    T myStackArray<T>::getTop(){

        if (isEmpty()){
            cout << "Stack is Empty!\n";
            return -1;       
        }

        return this->array[this->top];
    }

    template <class T> 
    int myStackArray<T>::getSize(){
        return this->top+1;
    }

    template <class T>
    void myStackArray<T>::display(){

        if(isEmpty()){
            cout << "Empty Stack!\n";
            return;
        }    

        for(int i=0; i <= this->top; i++)
            cout << this->array[i] << " ";
        cout <<endl;    
    }
