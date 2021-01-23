#include <bits/stdc++.h>
using namespace std;

namespace mySingleLinkedList{

    struct Node {
        int data;
        Node * next;
    }*head=NULL;

    
    void emptyLLMSG(){
        cout << "Empty Linked List!\n";
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

        Node *linear = createLL(vec);
        Node *circular = linear;

        while (linear->next)
            linear = linear->next;
        
        linear->next = circular;

        return circular;
    }
    
    Node *getLastNodeLL(Node *first){

        while ( (first->next != head) && first->next ) 
            first = first->next;
        
        return first;
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

    bool isCyclicLL(Node *first){

        if (isEmptyLL(first)){
            emptyLLMSG();
            return false;
        }

        if(getLastNodeLL(first)->next == head)
            return true;
        
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

    void reverseLL(Node *first){

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
            // Break if circular 
            if (temp == head) 
                break;
        }
        //make it circular after reversing
        if (temp)
            head->next = curr;

        head = curr; 

    }
    
    void insertNodeLL(Node *first, int index, int value){

        int lengthLL = getSizeLL(first);
        
        if (index  > lengthLL || index < 0){
            cout << "Index is out of Linked List size!\n";
            return;
        }
            
        Node *temp = new Node; 
        temp->data = value;

        if (index == 0){
            Node *last = getLastNodeLL(head);

            temp->next = head;

            if (last->next == head)
                last->next = temp;
            
            head = temp;
            temp = NULL; delete temp;
        }
        else{
            
            for(int i=0; i < index-1; i++)
                first = first->next;
                
            temp->next = first->next;
            first->next = temp;
        }
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
        
        Node *temp = new Node;

        if (index == 0){
            Node *last = getLastNodeLL(head);

            temp = head->next;

            if(last->next == head)
               last->next = temp; 
            
            head = temp;
            temp = NULL; delete temp;
        }            
        else {
            for (int i=0; i<index-1; i++)
                first = first->next;
                       
            temp = first->next;
            first->next = temp->next;
            temp = NULL; delete temp;
        }     
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
} // namespace mySingleLinkedList