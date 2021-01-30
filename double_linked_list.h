#include <bits/stdc++.h>
using namespace std;


template <class T>
class myDoubleLinkedList{
    private:
        common::NodeDLL<T>* head;
        void deleteLL();
        common::NodeDLL<T>* createLL(vector<T> vec);
        common::NodeDLL<T>* createCircularLL(vector<T> vec);
    public:
        myDoubleLinkedList(){head = NULL;}
        myDoubleLinkedList(vector<T> vec, bool circular = false);
        ~myDoubleLinkedList();

        bool isEmpty();
        int getSize();
        void display();
        common::NodeDLL<T> *getLastNode();
        bool isSorted();
        bool isCyclic();
        void reverse();
        void insertNode(int index, T value);
        void deleteNode(int index);
        int searchNode(T key);
        myDoubleLinkedList<T> concatenate(myDoubleLinkedList<T> secondLL);
        myDoubleLinkedList<T> merge(myDoubleLinkedList<T> secondLL);
    
};

    template <class T>
    myDoubleLinkedList<T>::myDoubleLinkedList(vector<T> vec, bool circular){
        if(circular)
            head = createCircularLL(vec);
        else
            head = createLL(vec);
    }

    template <class T>
    myDoubleLinkedList<T>::~myDoubleLinkedList(){
        deleteLL();
    }


    template <class T>
    bool myDoubleLinkedList<T>::isEmpty(){
        return head == NULL ? 1 : 0;
    }

    template <class T>
    int myDoubleLinkedList<T>::getSize(){

        if (isEmpty())
            return 0;
        
        common::NodeDLL<T>* first = head;
        int count=0;

        while (first){
            count++;

            if (first->next == head) 
                break;

            first = first->next;
        }   
        
        return count;
    } 

    template <class T>
    void myDoubleLinkedList<T>::display(){

        if(isEmpty()){
            common::emptyLLMSG();
            return;
        }

        common::NodeDLL<T>* first = head;

        while(first){

            cout << first->data << " " ;

            if(first->next == head)
                break;

            first = first->next;
        }
        cout << endl;  
    }

    template <class T>
    common::NodeDLL<T>* myDoubleLinkedList<T>::createLL(vector<T> vec){

        if (!vec.size())
            return NULL;

        common::NodeDLL<T>* first = new common::NodeDLL<T>;
        common::NodeDLL<T>* last = first;

        first->data = vec[0];
        first->previous = first->next = NULL;

        for(int i = 1; i < vec.size(); i++){
            common::NodeDLL<T>* temp = new common::NodeDLL<T>;
            temp->data = vec[i];
            temp->next = last->next;
            temp->previous = last;
            last->next = temp;
            last = temp;
        }

        return first;    
    }

    template <class T>
    common::NodeDLL<T>* myDoubleLinkedList<T>::createCircularLL(vector<T> vec){

        common::NodeDLL<T>* linear = createLL(vec);
        common::NodeDLL<T>* circular = linear;

        while(linear->next)
            linear = linear->next;
        
        linear->next = circular;
        circular->previous = linear;
        
        return circular;
    }
    
    template <class T>
    void myDoubleLinkedList<T>::deleteLL(){

        common::NodeDLL<T>* eraser = head;

        while(head){
            head = head->next;
            delete eraser;
            eraser = head;
        }
    }

    template <class T>
    common::NodeDLL<T>* myDoubleLinkedList<T>::getLastNode(){
        
        if(isEmpty()){
            common::emptyLLMSG();
            return NULL;
        }
        
        common::NodeDLL<T>* first = head;

        if (first->previous)
            return first->previous;
        
        while(first->next)
            first = first->next;
        
        return first;
    }


    template <class T>
    bool myDoubleLinkedList<T>::isSorted(){
        
        if (isEmpty()){
            common::emptyLLMSG();
            return false;
        }

        common::NodeDLL<T>* first = head;
        int lengthLL = getSize();

        for (int i=0; i < lengthLL-1; i++){
            if (first->data > (first->next)->data)
                return false;
            if (first->next == head)
                break;
            
            first = first->next;    
        }
        
        return true;
    }
    
    template <class T>
    bool myDoubleLinkedList<T>::isCyclic(){
        
        if (isEmpty()){
            common::emptyLLMSG();
            return false;
        }

        if(getLastNode()->next == head)
            return true;
        
        common::NodeSLL<T>* first = head;
        common::NodeSLL<T>* curr  = first, *prev = curr;
        
         while (curr){  

            prev = prev->next;
            curr = curr->next;
            curr = curr ? curr->next : NULL; 

            if ((curr == prev) && curr)
                return true;    
        }
        
        return false;        
        
    }

    template <class T>
    void myDoubleLinkedList<T>::reverse(){

        if (isEmpty()){
            common::emptyLLMSG();
            return;
        }

        common::NodeDLL<T>* first = head;
        common::NodeDLL<T>* temp = first;

        while(temp){

            temp = first->next;
            first->next = first->previous;
            first->previous = temp;

            if (!temp || temp == head){
                head = first;
                break;
            }
                
            first = first->previous;
        }

    }

    template <class T>
    void myDoubleLinkedList<T>::insertNode(int index, T value){

        int lengthLL = getSize();
        
        if (index  > lengthLL || index < 0){
            cout << "Index is out of Linked List size!\n";
            return;
        }

        common::NodeDLL<T>* first = head;
        common::NodeDLL<T>* last = getLastNode();
        common::NodeDLL<T>* temp = new common::NodeDLL<T>; 
        temp->data = value;
         

        if (index == 0){
            
            temp->next = head;
            head->previous = temp;

            if (last->next == head){
                last->next = temp;
                temp->previous = last;
            }
                
            head = temp;
        }
        else{
            
            for(int i=0; i < index-1; i++)
                first = first->next;
                
            temp->next = first->next;

            if (last->next == head)
                first->next->previous = temp;
            
            first->next = temp;
            temp->previous = first;
        }    
    }

    template <class T>
    void myDoubleLinkedList<T>::deleteNode(int index){
        
        if (isEmpty()){
            common::emptyLLMSG();
            return;
        }
            
        if (index <0 || index >= getSize()){
            cout << "Index is out of Linked List size!\n";  
            return;
        } 
        
        common::NodeDLL<T>* first = head;
        common::NodeDLL<T>* temp = new common::NodeDLL<T>;

        if (index == 0){
            common::NodeDLL<T>* last = getLastNode();

            temp = head->next;

            if(last->next == head){
                last->next = temp;
                temp->previous = last; 
            }
               
            
            head = temp;
        }            
        else {
            for (int i=0; i<index-1; i++)
                first = first->next;
                       
            temp = first->next;
            first->next = temp->next;
        }     
    }

    template <class T>
    myDoubleLinkedList<T> myDoubleLinkedList<T>::concatenate(myDoubleLinkedList<T> secondLL){

        myDoubleLinkedList<T> concatenated;

        if(isEmpty() && secondLL.isEmpty()){
            cout << "Empty Linked Lists!\n";
            return concatenated; 
        }

        if (isEmpty())
            return secondLL;
        if (secondLL.isEmpty())
            return *this;
       
        common::NodeDLL<T>* first = head;
        concatenated.head = first;

        while(first->next)
            first = first->next;
        
        first->next = secondLL.head;
        secondLL.head->previous = first;
        
        return concatenated;              
    }

    template <class T>
    myDoubleLinkedList<T> myDoubleLinkedList<T>::merge(myDoubleLinkedList<T> secondLL){
        
        myDoubleLinkedList<T> merged;

        if(isEmpty() && secondLL.isEmpty()){
            cout << "Empty Linked Lists!\n";
            return merged; 
        }
        
        if (isEmpty())
            return secondLL;
        if (secondLL.isEmpty())
            return *this;
        
        if ( !isSorted() && !secondLL.isSorted()){
            cout << "Merging requires 2 sorted Linked Lists!\n";
            return NULL;
        }

        common::NodeDLL<T>* first = head;
        common::NodeDLL<T>* second = secondLL.head;

        if (first->data < second->data){
            merged.head = first;
            first = first->next;
        }   
        else{
            merged.head = second;
            second= second->next;
        }

        common::NodeDLL<T>* temp = merged.head;

        while(first && second){
            if (first->data < second->data){
                temp->next = first;
                first->previous = temp;
                temp = first;
                first = first->next;
            }       
            else{
                temp->next = second;
                second->previous = temp;
                temp = second;
                second = second->next; 
            }            
        } 
        
        if (!first){
            temp->next = second;
            second->previous = temp;
        }
            
        if (!second){
            temp->next = first;
            first->previous = temp;
        }

        return merged;
    }

    template <class T>
    int myDoubleLinkedList<T>::searchNode(T key){

        if (isEmpty()){
            common::emptyLLMSG();
            return -1;
        }

        common::NodeDLL<T>* first = head;
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

