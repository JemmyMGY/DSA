#include<bits/stdc++.h>
using namespace std;

namespace common{

    void starter(){
        ios::sync_with_stdio(0);
        cin.tie(0);
    }

    void emptyLLMSG(){
        cout << "Empty Linked List!\n";
    }

    void emptyStackMSG(){
        cout << "Empty Stack!\n";
    }

    void emptyQueueMSG(){
        cout << "Queue is Empty\n";
    }

    template <class T>
    class NodeSLL{
    public:
        T data;
        NodeSLL* next;
    };

    template <class T>
    class NodeDLL{
    public:
        T data;
        NodeDLL<T>* next;
        NodeDLL<T>* previous;
    };


}