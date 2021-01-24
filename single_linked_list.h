#include <bits/stdc++.h>
using namespace std;

template <class T>
class NodeSLL{
    public:
        T data;
        NodeSLL* next;
        void display();    
};

template <class T>
class mySingleLinkedList{
    private:
        NodeSLL<T>* head;
        void deleteLL();
        NodeSLL<T>* createLL(vector<T> vec);
        NodeSLL<T>* createCircularLL(vector<T> vec);
    public:
        mySingleLinkedList(){this->head = NULL;}
        mySingleLinkedList(vector<T> vec, bool circular = false);
        ~mySingleLinkedList();  

        bool isEmpty();
        int getSize();
        void display();
        NodeSLL<T> *getLastNode();
        bool isSorted();
        bool isCyclic();
        void reverse();
        void insertNode(int index, T value);
        void deleteNode(int index);
        mySingleLinkedList<T> concatenate(mySingleLinkedList<T> secondLL);
        mySingleLinkedList<T> merge(mySingleLinkedList<T> secondLL);

};


    void emptyLLMSG(){
        cout << "Empty Linked List!\n";
    }

    template <class T>
    mySingleLinkedList<T>::mySingleLinkedList(vector<T> vec, bool circular){
       
        if(circular)
            this->head = createCircularLL(vec);
        else
            this->head = createLL(vec);    
    }
    
    template <class T>
    mySingleLinkedList<T>::~mySingleLinkedList(){      
        deleteLL();
    }
    

// functions 
    template <class T>
    bool mySingleLinkedList<T>::isEmpty(){
        return this->head == NULL ? true : false;    
    }

    template <class T>
    int mySingleLinkedList<T>::getSize(){
        
        NodeSLL<T>* first = this->head;

        if (this->isEmpty())
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

    template <class T>
    void mySingleLinkedList<T>::display(){

        if(isEmpty()){
            emptyLLMSG();
            return;
        }

        NodeSLL<T>* first = this->head;

        while(first){
            cout << first->data << " " ;

            if(first->next == this->head)
                break;

            first = first->next;
        }
        cout << endl;  
    }

    template <class T>
    NodeSLL<T>* mySingleLinkedList<T>::createLL(vector <T> vec ){
        
        if (!vec.size())
            return NULL;

        NodeSLL<T>* first =new  NodeSLL<T>;
        NodeSLL<T>* last =first ;
        
        first->data = vec[0];
        first->next = NULL;
    
        for(int i=1; i < vec.size(); i++){
            NodeSLL<T>* temp = new NodeSLL<T>;
            temp->data = vec[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        
        return first;
    }

    template <class T>
    NodeSLL<T>* mySingleLinkedList<T>::createCircularLL(vector<T> vec){

        NodeSLL<T>* circular =   createLL(vec); 
        NodeSLL<T>* linear =  circular;

        while (linear->next)
            linear = linear->next;
        
        linear->next = circular;
    
        return circular;
    }

    template <class T>
    void mySingleLinkedList<T>::deleteLL(){

        NodeSLL<T>* eraser = this->head;

        while(this->head){
            this->head = this->head->next;
            eraser=NULL;delete eraser;
            eraser = this->head;
        }
    }

    template <class T>
    NodeSLL<T>* mySingleLinkedList<T>::getLastNode(){

        if(isEmpty()){
            emptyLLMSG();
            return NULL;
        }

        NodeSLL<T> *first = this->head;

        while ( (first->next != this->head) && first->next ) 
            first = first->next;
        
        return first;
    }

    template <class T>
    bool mySingleLinkedList<T>::isSorted(){
        
        if (this->isEmpty()){
            emptyLLMSG();
            return false;
        }

        NodeSLL<T> *first = this->head;

        int lengthLL = this->getSize();

        for (int i=0; i < lengthLL-1; i++){
            if (first->data > (first->next)->data)
                return false;
            if (first->next == this->head)
                break;
            
            first = first->next;    
        }
        
        return true;
    }
    
    template <class T>
    bool mySingleLinkedList<T>::isCyclic(){
        
        if (isEmpty()){
            emptyLLMSG();
            return false;
        }

        NodeSLL<T> *first = this->head;

        if(this->getLastNode()->next == this->head)
            return true;
        
        NodeSLL<T> *curr, *prev = first;
        
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
    void mySingleLinkedList<T>::reverse(){
        
        if (this->isEmpty()){
            emptyLLMSG();
            return;
        }

        NodeSLL<T> *temp=this->head,*prev,*curr = NULL;

        while(temp){
            prev = curr;
            curr = temp;
            temp = temp->next;
            curr->next= prev;
            // Break if circular 
            if (temp == this->head) 
                break;
        }
        //make it circular after reversing
        if (temp)
            this->head->next = curr;

        this->head = curr; 
    }

    template <class T>
    void mySingleLinkedList<T>::insertNode(int index, T value){
         
        int lengthLL = getSize();
        
        if (index  > lengthLL || index < 0){
            cout << "Index is out of Linked List size!\n";
            return;
        }
        
        NodeSLL<T>*first = this->head; 
        NodeSLL<T> *temp = new NodeSLL<T>; 
        temp->data = value;
        
        if (index == 0){
            
            NodeSLL<T> *last = getLastNode();

            temp->next = this->head;

            if (last->next == this->head)
                last->next = temp;
            
            this->head = temp;
            temp=NULL; delete temp;
        }
        else{
            
            for(int i=0; i < index-1; i++)
                first = first->next;
                
            temp->next = first->next;
            first->next = temp;
        }
    }

    template <class T>
    void mySingleLinkedList<T>::deleteNode(int index){
        
        if (isEmpty()){
            emptyLLMSG();
            return;
        }
            
        if (index <0 || index >= getSize()){
            cout << "Index is out of Linked List size!\n";  
            return;
        } 
        
         NodeSLL<T>* temp = new NodeSLL<T>;
         NodeSLL<T>* first = this->head;

        if (index == 0){
             NodeSLL<T>* last = getLastNode();

            temp = this->head->next;

            if(last->next == this->head)
               last->next = temp; 
            
            this->head = temp;
        }            
        else {
            for (int i=0; i<index-1; i++)
                first = first->next;
                       
            temp = first->next;
            first->next = temp->next;
        }

        temp = NULL;delete temp;    
    }

    template <class T>
    mySingleLinkedList<T> mySingleLinkedList<T>::concatenate(mySingleLinkedList<T> secondLL){
        
        mySingleLinkedList<T> concatenated;

        if(this->isEmpty() &&  secondLL.isEmpty() ){
            cout << "Empty Linked Lists!\n";
            return concatenated; 
        }

        if (this->isEmpty())
            return secondLL;
        if (secondLL.isEmpty())
            return *this;    
        

        NodeSLL<T>* first = this->head;
        concatenated.head = first;

        while(first->next)
            first = first->next;
        
        first->next = secondLL.head;
        
        return concatenated;              
    }

    template <class T>
    mySingleLinkedList<T> mySingleLinkedList<T>::merge(mySingleLinkedList<T> secondLL){
        
        mySingleLinkedList<T> merged;
        
        if(this->isEmpty() && secondLL.isEmpty()){
            cout << "Empty Linked Lists!\n";
            return merged; 
        }

        if ( !this->isSorted() && !secondLL.isSorted()){
            cout << "Merging requires 2 sorted Linked Lists!\n";
            return merged;
        }
        
        if (this->isEmpty())
            return secondLL;
        if (secondLL.isEmpty())
            return *this;

        

        NodeSLL<T>* first = this->head; 
        merged.head = NULL;

        if (first->data < secondLL.head->data){
            merged.head = first;
            first = first->next;
        }   
        else{
            merged.head = secondLL.head;
            secondLL.head= secondLL.head->next;
        }

        NodeSLL<T>* temp = merged.head;      
        
        while(first && secondLL.head ){
            if (first->data < secondLL.head->data){
                temp->next = first;
                temp = first;
                first = first->next;
            }       
            else{
                temp->next = secondLL.head;
                temp = secondLL.head;
                secondLL.head = secondLL.head->next; 
            }            
        } 
        
        if (!first)
            temp->next = secondLL.head;
        if (!secondLL.head)
            temp->next = first;

        return merged;           
    }

