#include <bits/stdc++.h>
#include "single_linked_list.h"
#include "double_linked_list.h"
#include "stack_array.h"
using namespace std;

void starter(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main(){
    
    starter();
    

    // stack testing 

    myStackArray::Stack stk;

    cout << myStackArray::isEmpty(stk) <<endl;
    myStackArray::push(stk, 55);
    myStackArray::push(stk, 60);
    myStackArray::push(stk, 80);
    cout << myStackArray::isEmpty(stk) <<endl;

    cout << myStackArray::getSize(stk) <<endl;

    cout << myStackArray::pop(stk) <<endl;
    cout << myStackArray::pop(stk) <<endl;
    cout << myStackArray::pop(stk) <<endl;

    cout << myStackArray::getSize(stk) <<endl;




    // Linked List testing 


   /*  vector<int> v1 {2,8,10,11};
    vector<int> v2 {3,5,7};
    vector <int> v { 10,20,50,80 };
    
    mySingleLinkedList::Node *lls1 = mySingleLinkedList::createLL(v1);
    mySingleLinkedList::Node *lls2 = mySingleLinkedList::createLL(v2);

    myDoubleLinkedList::Node *lld1 = myDoubleLinkedList::createLL(v1);
    myDoubleLinkedList::Node *lld2 = myDoubleLinkedList::createLL(v2); */
    
    /*mySingleLinkedList::head = mySingleLinkedList::createCircularLL(v);
    mySingleLinkedList::displayLL(mySingleLinkedList::head);*/
    
   /*  myDoubleLinkedList::head = myDoubleLinkedList::createLL(v);
    cout << myDoubleLinkedList::getLastNodeLL(myDoubleLinkedList::head)->data <<endl;
 */
    /* myDoubleLinkedList::Node * merged = myDoubleLinkedList::mergeLL(lld1, lld2);
    myDoubleLinkedList::displayLL(merged);
    myDoubleLinkedList::displayNextPreviousLL(merged); */

    /* myDoubleLinkedList::Node * concatenated = myDoubleLinkedList::concatenateLL(lld1, lld2);
    myDoubleLinkedList::displayLL(concatenated);
    myDoubleLinkedList::displayNextPreviousLL(concatenated); */


    /* myDoubleLinkedList::head = myDoubleLinkedList::createLL(v);
    //myDoubleLinkedList::head = myDoubleLinkedList::createCircularLL(v);
    myDoubleLinkedList::deleteNodeLL(myDoubleLinkedList::head,0);
    myDoubleLinkedList::displayLL(myDoubleLinkedList::head); */
    
    /* myDoubleLinkedList::head = myDoubleLinkedList::createLL(v);
    //myDoubleLinkedList::head = myDoubleLinkedList::createCircularLL(v);
    myDoubleLinkedList::insertNodeLL(myDoubleLinkedList::head,3,88888);
    myDoubleLinkedList::displayLL(myDoubleLinkedList::head); */
    
    
/*     myDoubleLinkedList::head = myDoubleLinkedList::createLL(v);
    //myDoubleLinkedList::head = myDoubleLinkedList::createCircularLL(v);
    myDoubleLinkedList::reverseLL(myDoubleLinkedList::head);
    myDoubleLinkedList::displayLL(myDoubleLinkedList::head); */

    /* mySingleLinkedList::head = mySingleLinkedList::createCircularLL(v);
    mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    mySingleLinkedList::displayLL(mySingleLinkedList::head); */




    /* mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    mySingleLinkedList::head = mySingleLinkedList::createCircularLL(v);
    mySingleLinkedList::reverseLL(mySingleLinkedList::head);
    mySingleLinkedList::displayLL(mySingleLinkedList::head); */
    
    
    /* mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    mySingleLinkedList::insertNodeLL(mySingleLinkedList::head,4,88888);
    mySingleLinkedList::displayLL(mySingleLinkedList::head); */
    
    /* mySingleLinkedList::Node *concatenated = mySingleLinkedList::concatenateLL(ll1,ll2);
    mySingleLinkedList::displayLL(concatenated); */

    /* mySingleLinkedList::Node *merged = mySingleLinkedList::mergeLL(ll1,ll2);
    mySingleLinkedList::displayLL(merged); */

    /* mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    mySingleLinkedList::insertNodeLL(mySingleLinkedList::head,1,88888);
    mySingleLinkedList::insertNodeLL(mySingleLinkedList::head,0,50);
    mySingleLinkedList::displayLL(mySingleLinkedList::head); */


    /* mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    mySingleLinkedList::deleteNodeLL(mySingleLinkedList::head, 2);
    mySingleLinkedList::displayLL(mySingleLinkedList::head); */

    
   /*  mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    cout << mySingleLinkedList::isSortedLL(mySingleLinkedList::head) <<endl; */

    
    /* mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    mySingleLinkedList::reverseLL(mySingleLinkedList::head);
    mySingleLinkedList::displayLL(mySingleLinkedList::head); */


   /*  mySingleLinkedList::head = mySingleLinkedList::createLL(v);
    cout << mySingleLinkedList::isCyclicLL(mySingleLinkedList::head) <<endl; */
}


