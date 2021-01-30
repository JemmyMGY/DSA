#include <bits/stdc++.h>
using namespace std;


template <class T>
class mySingleLinkedList{
    private:
        common::NodeSLL<T>* head;
        void deleteLL();
        common::NodeSLL<T>* createLL(vector<T> vec);
        common::NodeSLL<T>* createCircularLL(vector<T> vec);
    public:
        mySingleLinkedList(){head = NULL;}
        mySingleLinkedList(vector<T> vec, bool circular = false);
        ~mySingleLinkedList();

        bool isEmpty();
        int getSize();
        void display();
        common::NodeSLL<T> *getLastNode();
        bool isSorted();
        bool isCyclic();
        void reverse();
        void insertNode(int index, T value);
        void deleteNode(int index);
        int searchNode(T key);
        mySingleLinkedList<T> concatenate(mySingleLinkedList<T>* secondLL);
        mySingleLinkedList<T> merge(mySingleLinkedList<T>* secondLL);

};

    template <class T>
    mySingleLinkedList<T>::mySingleLinkedList(vector<T> vec, bool circular) {
        if(circular)
            head = createCircularLL(vec);
        else
            head = createLL(vec);
    }


    template <class T>
    mySingleLinkedList<T>::~mySingleLinkedList(){
        deleteLL();
    }


    template <class T>
    bool mySingleLinkedList<T>::isEmpty(){
        return head == NULL ? 1 : 0;
    }

    template <class T>
    int mySingleLinkedList<T>::getSize(){

        if (isEmpty())
            return 0;
        
        common::NodeSLL<T>* first = head;
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
            common::emptyLLMSG();
            return;
        }

        common::NodeSLL<T>* first = head;

        while(first){
            cout << first->data << " " ;

            if(first->next == head)
                break;

            first = first->next;
        }
        cout << endl;  
    }

    template <class T>
    common::NodeSLL<T>* mySingleLinkedList<T>::createLL(vector <T> vec ){
        
        if (!vec.size())
            return NULL;

        common::NodeSLL<T>* first =new  common::NodeSLL<T>;
        common::NodeSLL<T>* last =first ;
        
        first->data = vec[0];
        first->next = NULL;
    
        for(int i=1; i < vec.size(); i++){
            common::NodeSLL<T>* temp = new common::NodeSLL<T>;
            temp->data = vec[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        
        return first;
    }

    template <class T>
    common::NodeSLL<T>* mySingleLinkedList<T>::createCircularLL(vector<T> vec){

        common::NodeSLL<T>* circular =  createLL(vec);
        common::NodeSLL<T>* linear =  circular;

        while (linear->next)
            linear = linear->next;
        
        linear->next = circular;
    
        return circular;
    }

    template <class T>
    void mySingleLinkedList<T>::deleteLL(){

        common::NodeSLL<T>* eraser = head;

        while(head){

            head = head->next;
            delete eraser;
            eraser = head;
        }
    }

    template <class T>
    common::NodeSLL<T>* mySingleLinkedList<T>::getLastNode(){

        if(isEmpty()){
          common::emptyLLMSG();
            return NULL;
        }

        common::NodeSLL<T> *first = head;

        while ( (first->next != head) && first->next )
            first = first->next;
        
        return first;
    }

    template <class T>
    bool mySingleLinkedList<T>::isSorted(){
        
        if (isEmpty()){
            common::emptyLLMSG();
            return false;
        }

        common::NodeSLL<T>* first = head;

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
    bool mySingleLinkedList<T>::isCyclic(){
        
        if (isEmpty()){
            common::emptyLLMSG();
            return false;
        }

        common::NodeSLL<T>* first = head;

        if(getLastNode()->next == head)
            return true;
        
        common::NodeSLL<T>* curr, *prev = first;
        
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
        
        if (isEmpty()){
            common::emptyLLMSG();
            return;
        }

        common::NodeSLL<T>* temp = head, *prev, *curr = NULL;

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

    template <class T>
    void mySingleLinkedList<T>::insertNode(int index, T value){
         
        int lengthLL = getSize();
        
        if (index  > lengthLL || index < 0){
            cout << "Index is out of Linked List size!\n";
            return;
        }
        
        common::NodeSLL<T>* first = head;
        common::NodeSLL<T>* temp = new common::NodeSLL<T>; 
        temp->data = value;
        
        if (index == 0){
            
            common::NodeSLL<T>* last = getLastNode();

            temp->next = head;

            if (last->next == head)
                last->next = temp;
            
            head = temp;
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
            common::emptyLLMSG();
            return;
        }
            
        if (index <0 || index >= getSize()){
            cout << "Index is out of Linked List size!\n";  
            return;
        } 
        
         common::NodeSLL<T>* temp = new common::NodeSLL<T>;
         common::NodeSLL<T>* first = head;

        if (index == 0){
             common::NodeSLL<T>* last = getLastNode();

            temp = head;

            if(last->next == head)
               last->next = head->next;
            
            head = head->next;
        }            
        else {
            for (int i=0; i<index-1; i++)
                first = first->next;
                       
            temp = first->next;
            first->next = temp->next;
        }

        free(temp);
    }

    template <class T>
    mySingleLinkedList<T> mySingleLinkedList<T>::concatenate(mySingleLinkedList<T>* secondLL){
        
        mySingleLinkedList<T>* concatenated;

        if( isEmpty() &&  secondLL->isEmpty() ){
            cout << "Empty Linked Lists!\n";
            return *concatenated; 
        }

        if (isEmpty())
            return *secondLL;
        if (secondLL->isEmpty())
            return *this;    
        

        
        common::NodeSLL<T>* first = head;
        concatenated->head = head;

        while(first->next)
            first = first->next;
        
        first->next = secondLL->head;
        
        return *concatenated; 
    }

    template <class T>
    mySingleLinkedList<T> mySingleLinkedList<T>::merge(mySingleLinkedList<T>* secondLL){
        
        mySingleLinkedList<T>* merged;
        
        if(isEmpty() && secondLL->isEmpty()){
            cout << "Empty Linked Lists!\n";
            return *merged; 
        }

        if ( !isSorted() && !secondLL->isSorted()){
            cout << "Merging requires 2 sorted Linked Lists!\n";
            return *merged;
        }
        
        if (isEmpty())
            return *secondLL;
        if (secondLL->isEmpty())
            return *this;

        

        common::NodeSLL<T>* first = head;
        common::NodeSLL<T>* second = secondLL->head;

        if (first->data < second->data){
            merged->head = first;
            first = first->next;
        }   
        else{
            merged->head = second;
            second = second->next;
        }

        common::NodeSLL<T>* temp = merged->head;      
        
        while(first && second ){
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

        return *merged;
    }

    template<class T>
    int mySingleLinkedList<T>::searchNode(T key) {

        if (isEmpty()){
            common::emptyLLMSG();
            return -1;
        }

        common::NodeSLL<T>* first = head;
        int index =0;

        while (first){
            if (first->data == key)
                return first->data;

            index++;

            if (first->next == head)
                break;

            first = first->next;
        }

        return -1;
    }


















