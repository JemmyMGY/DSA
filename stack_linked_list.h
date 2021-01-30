#include<bits/stdc++.h>
using namespace std;

template <class T>
class myStackLL{

    private:
        common::NodeSLL<T>* top;
        void clearStack();
    public:
        myStackLL(){
            top = NULL;
        };
        ~myStackLL(){
            clearStack();
        };

        bool isEmpty();
        bool isFull();
        void push(T value);
        T pop();
        T getTop();
        int getSize();
        void display();
};


    template <class T>
    void myStackLL<T>::clearStack() {

        if (isEmpty())
            return;

        common::NodeSLL<T>* first = top;

        while (top){
            top = top->next;
            delete first;
            first = top;
        }
    }

    template <class T>
    bool myStackLL<T>::isEmpty() {
        return top == NULL ? 1 : 0;
    }

    template<class T>
    bool myStackLL<T>::isFull() {

        common::NodeSLL<T>* newNode = new common::NodeSLL<T>;

        return newNode == NULL ? 1 : 0;
    }

    template<class T>
    void myStackLL<T>::push(T value) {

        common::NodeSLL<T>* newNode = new common::NodeSLL<T>;

        if(!newNode){
            cout << "Stack overflow!";
            return;
        }

        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    template<class T>
    T myStackLL<T>::pop() {

        T topData;

        if(isEmpty()){
            cout << "Stack underflow!\n";
            return topData;
        }

        common::NodeSLL<T>* temp = top;
        top = top->next;


        topData = temp->data;
        delete temp;

        return topData;
    }

    template<class T>
    T myStackLL<T>::getTop() {

        if (isEmpty()){
            cout << "Stack is empty!\n";
            T empty;
            return empty;
        }

        return top->data;
    }

    template<class T>
    int myStackLL<T>::getSize() {

        if (isEmpty()){
            common::emptyStackMSG();
            return -1;
        }

        common::NodeSLL<T>* first = top;
        int index =0;

        while (first){
            index++;
            first = first->next;
        }

        return index;
    }

    template<class T>
    void myStackLL<T>::display() {
        if (isEmpty()){
            common::emptyStackMSG();
            return;
        }

        common::NodeSLL<T>* first = top;

        while (first){
            cout << first->data << " ";
            first = first->next;
        }
        cout << "\n";
    }