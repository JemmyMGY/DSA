#include <bits/stdc++.h>
#include "single_linked_list.h"
#include "double_linked_list.h"
#include "stack_array.h"
using namespace std;

void starter(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}


int main(){
    
    starter();
    

    // stack testing 
/*     myStackArray<int> stak(10);

    stak.push(5);
    stak.push(80);
    stak.push(10);
    stak.push(12);
    stak.push(9);
    stak.push(500);
    stak.push(8);
    stak.push(100);
    stak.push(120);
    stak.push(90);

    cout << stak.isFull() <<endl;
    stak.push(0);
    stak.display();
    cout << stak.pop() <<endl;
    cout << stak.getSize() <<endl;
    cout << stak.getTop() <<endl;
    cout << stak.isFull() <<endl;
     */

    vector<int> v{1,2,5,10};
    mySingleLinkedList<int> LL(v, true);
    LL.display();
    /* LL.~mySingleLinkedList();
    cout << LL.getSize() << endl; */

   /*  cout << LL.getSize()<<endl;
    NodeSLL<int>* last = LL.getLastNode();
    LL.insertNode(1,100);
    LL.display(); */
  /*  LL.deleteNode(0);
    LL.display();
    LL.insertNode(0,0);
    LL.insertNode(5,100);
    cout << LL.isSorted() <<endl;
    LL.insertNode(1,1000);
    cout << LL.isSorted() <<endl; */
    //cout << LL.getLastNode()->next->data <<endl;
    

}


