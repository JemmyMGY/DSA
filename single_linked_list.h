#include <bits/stdc++.h>
using namespace std;

namespace myLinkedList{

    struct Node {
        int data;
        Node * next;
    }*head=NULL;

    
    void emptyLLMSG(){
        cout << "Empty Linked List!\n";
    }
    
    Node *createLL (vector <int> vec ){
        
        if (!vec.size())
            return NULL;

        Node *first, *last, *temp;
        first = new Node;
        last = new Node;
        
        first->data = vec[0];
        first->next = NULL;
        last = first;

        for(int i=1; i < vec.size(); i++){
            temp = new Node;
            temp->data = vec[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        
        return first;
    }
    
    Node *createCircularLL(vector<int> vec){

        Node *single = createLL(vec);
        Node *circular = single;

        while (single->next)
            single = single->next;
        single->next = circular;

        return circular;
    }
    

    bool isEmptyLL(Node *first){
        return first == NULL ? true : false;    
    }
   
    
    int getSizeLL(Node *first ){

        if (isEmptyLL(first))
            return 0;
        
        
        int count=0;

        while (first){
            count++;

            if (first->next == head) 
                break;

            first = first->next;
        }   
        
        return count;
    } 

    void displayLL( Node *first){

        if(isEmptyLL(first)){
            emptyLLMSG();
            return;
        }
            
        while(first){
            cout << first->data << " " ;

            if(first->next == head)
                break;

            first = first->next;
        }
        cout << endl;  
    }

    void insertNodeLL(Node *first, int index, int value){

        int length = getSizeLL(first);
        
        if (index  > length || index < 0){
            cout << "Index is out of Linked List size!\n";
            return;
        }
            
        Node *temp = new Node; 
        temp->data = value;

        if (index == 0){
            temp->next =  head;
            head = temp;
        }
        else{
            int i=0;
            for(; i < index-1; i++)
                first = first->next;
                
            temp->next = first->next;
            first->next = temp;
        }
    }

    int searchNodeLL(Node *first, int key){

        if (isEmptyLL(first))
            return -1;
        
        int index=0;

        while (first){

            if (key == first->data)
                return index;

            index++;

            if (first->next == head)
                break;

            first = first->next;    
        }
        
        return -1;   
    }

    void deleteNodeLL( Node *first, int index){
        
        if (isEmptyLL(first)){
            emptyLLMSG();
            return;
        }
            
        if (index <0 || index >= getSizeLL(first)){
            cout << "Index is out of Linked List size!\n";  
            return;
        } 
       
        if (index == 0){
            head= head->next;
            delete first;
        }            
        else {
            int i=0;
            for (;i<index-1; i++)
                first = first->next;
            
            Node *temp = new Node;
            temp = first->next;
            first->next = temp->next;
            temp = NULL;
            delete temp;
        }     
    }

    bool isSortedLL(Node *first){
    
        if (isEmptyLL(first)){
            emptyLLMSG();
            return false;
        }

        int lengthLL = getSizeLL(first);

        for (int i=0; i < lengthLL-1; i++){
            if (first->data > (first->next)->data)
                return false;
            if (first->next == head)
                break;
            
            first = first->next;    
        }
        
        return true;
    }

    void reverseLLElements(Node *first){
        
        if (isEmptyLL(first)){
            emptyLLMSG();
            return;
        }
        
        int lengthLL = getSizeLL(first);
        int temp [lengthLL];

        Node *current = head;
        
        for (int i=0; i<lengthLL; i++){
            temp[i] = current->data;
            current = current->next;
        }

        current = first;

        for (int i=0; i < lengthLL; i++){
            current->data = temp[lengthLL-1-i];
            current = current->next;
        }
    }

    void reverseLLPointers(Node *first){

        if (isEmptyLL(first)){
            emptyLLMSG();
            return;
        }

        Node *temp=head,*prev,*curr = NULL;

        while(temp){
           prev = curr;
           curr = temp;
           temp = temp->next;
           curr->next= prev;
        }
        head = curr;
    } 

    Node *concatenateLL(Node *first, Node *second){

        if(isEmptyLL(first) && isEmptyLL(second)){
            cout << "Empty Linked Lists!\n";
            return NULL; 
        }

        if (isEmptyLL(first))
            return second;
        if (isEmptyLL(second))
            return first;
       
        Node *concatenated = first;

        while(first->next)
            first = first->next;
        first->next = second;
        
        return concatenated;              
    }

    Node *mergeLL(Node *first, Node *second){
        
        if(isEmptyLL(first) && isEmptyLL(second)){
            cout << "Empty Linked Lists!\n";
            return NULL; 
        }
        
        if (isEmptyLL(first))
            return second;
        if (isEmptyLL(second))
            return first;
        
        if ( !isSortedLL(first) && !isSortedLL(second)){
            cout << "Merging requires 2 sorted Linked Lists!\n";
            return NULL;
        }

        Node *merged = new Node;
        
        if (first->data < second->data){
            merged = first;
            first = first->next;
        }   
        else{
            merged = second;
            second= second->next;
        }

        Node *temp = merged;      
        
        while(first && second){
            if (first->data < second->data){
                temp->next = first;
                temp = first;
                first = first->next;
            }       
            else{
                temp->next = second;
                temp = second;
                second = second->next; 
            }            
        } 
        
        if (!first)
            temp->next = second;
        if (!second)
            temp->next = first;

        return merged;           
    }

    bool isCyclicLL(Node *first){

        if (isEmptyLL(first)){
            emptyLLMSG();
            return false;
        }
        
        Node *curr, *prev = first;
        
         while (curr){  
            prev = prev->next;
            curr = curr->next;
            curr = curr ? curr->next : NULL; 

            if ((curr == prev) && curr)
                return true;    
        }
        
        return false;        
    }

}