#include <bits/stdc++.h>
#include "single_linked_list.h"
using namespace std;

void starter(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main(){
    
    starter();
    
    vector<int> v1 {2,8,10,11};
    vector<int> v2 {3,5};
    vector <int> v { 10,50,20,100,80 };
    
    myLinkedList::Node *ll1 = myLinkedList::createLL(v1);
    myLinkedList::Node *ll2 = myLinkedList::createLL(v2);

    
    /* myLinkedList::head = myLinkedList::createCircularLL(v);
    myLinkedList::displayLL(myLinkedList::head); */
    

    /* myLinkedList::Node *concatenated = myLinkedList::concatenateLL(ll1,ll2);
    myLinkedList::displayLL(concatenated); */

    /* myLinkedList::Node *merged = myLinkedList::mergeLL(ll1,ll2);
    myLinkedList::displayLL(merged); */

    /* myLinkedList::head = myLinkedList::createLL(v);
    myLinkedList::insertNodeLL(myLinkedList::head,1,88888);
    myLinkedList::insertNodeLL(myLinkedList::head,0,50);
    myLinkedList::displayLL(myLinkedList::head); */


    /* myLinkedList::head = myLinkedList::createLL(v);
    myLinkedList::deleteNodeLL(myLinkedList::head, 2);
    myLinkedList::displayLL(myLinkedList::head); */

    
   /*  myLinkedList::head = myLinkedList::createLL(v);
    cout << myLinkedList::isSortedLL(myLinkedList::head) <<endl; */

    
    /* myLinkedList::head = myLinkedList::createLL(v);
    myLinkedList::reverseLLPointers(myLinkedList::head);
    myLinkedList::displayLL(myLinkedList::head); */


   /*  myLinkedList::head = myLinkedList::createLL(v);
    cout << myLinkedList::isCyclicLL(myLinkedList::head) <<endl; */
}


