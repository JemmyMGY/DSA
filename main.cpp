#include <bits/stdc++.h>
#include "common.h"
#include "single_linked_list.h"
#include "double_linked_list.h"
#include "stack_array.h"
#include "stack_linked_list.h"
using namespace std;

int main(){
    
    common::starter();

    // stack testing 

//    myStackArray<char> stak(10);
//
//    cout << stak.getTop() <<endl;
//
//    stak.push('a');
//    stak.push('b');
//    stak.push('c');
//    stak.push('d');
//    stak.push('s');
//    stak.push('f');
//    stak.push('r');
//    stak.push('e');
//    stak.push('t');
//    stak.push('b');
//
//    cout << stak.isFull() <<endl;
//    stak.push('s');
//    stak.display();
//    cout << stak.pop() <<endl;
//    cout << stak.getSize() <<endl;
//    cout << stak.getTop() <<endl;
//    cout << stak.isFull() <<endl;


//    vector<int> v{15,20,50,60};
//    vector<int> v1{2,8,10,11};
//    vector<int> v2{3,5,7,80};
//
//    mySingleLinkedList<int> LL(v);
//    mySingleLinkedList<int> LL1(v1);
//    mySingleLinkedList<int> LL2(v2);
//
//    myDoubleLinkedList<int> ll(v);
//    myDoubleLinkedList<int> ll1(v1);
//    myDoubleLinkedList<int> ll2(v2);

    

//    LL.deleteNode(0);
//    LL.insertNode(1,80);
//    LL.display();


//    cout << LL.getSize()<<endl;
//    LL.insertNode(1,100);
//    LL.display();
//    LL.deleteNode(0);
//    LL.display();
//    LL.insertNode(0,90);
//    LL.display();
//    LL.insertNode(4,100);
//    LL.display();
//    cout << LL.isSorted() <<endl;
//    LL.insertNode(1,1000);
//    LL.display();
//    LL.~mySingleLinkedList();
//    cout << LL.getSize() << endl;
    
    
    
//    mySingleLinkedList<int> conc = LL1.concatenate(&LL2);
//    conc.display();

//    mySingleLinkedList<int> mer = LL1.merge(&LL2);
//    mer.display();

//stack linked list test
    myStackLL<char> stk;

    cout << stk.isEmpty() <<endl;
    cout << stk.getTop() <<endl;

    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.push('d');

    cout << stk.getTop() <<endl;
    stk.display();
    cout << stk.getSize() <<endl;
    cout << stk.isEmpty() <<endl;

}


