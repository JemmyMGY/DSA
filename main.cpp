#include <bits/stdc++.h>
#include "linked_list.h"
using namespace std;

void starter(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main(){
    starter();
    vector<int> v1 {2,8,10,11};
    vector<int> v2 {};
    myLinkedList::Node *ll1 = myLinkedList::createLL(v1);
    myLinkedList::Node *ll2 = myLinkedList::createLL(v2);

    //myLinkedList::concatenated = myLinkedList::concatenateLL(ll1,ll2);
    //myLinkedList::displayLL(myLinkedList::concatenated);

    myLinkedList::merged = myLinkedList::mergeLL(ll1,ll2);
    myLinkedList::displayLL(myLinkedList::merged);
    //myLinkedList::head = myLinkedList::createLL(v);

    //myLinkedList::insertNodeLL(myLinkedList::head,1,88888);
    //myLinkedList::insertNodeLL(myLinkedList::head,0,50);
    //myLinkedList::displayLL(myLinkedList::head);
    //myLinkedList::deleteNode(myLinkedList::head, 2);
    //myLinkedList::displayLL(myLinkedList::head);
    //cout << myLinkedList::isSortedLL(myLinkedList::head) <<endl;
    //myLinkedList::reverseLLPointers(myLinkedList::head);
    //myLinkedList::displayLL(myLinkedList::head);

}


