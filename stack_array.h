#include <bits/stdc++.h>
using namespace std;
# define MAX_SIZE 100
namespace myStackArray{
    
    struct Stack{
        
        int top =-1;
        int array[MAX_SIZE];
    };

    bool isEmpty(Stack stk){
        return stk.top == -1;
    }

    bool isFull(Stack stk){
        return stk.top == MAX_SIZE-1;
    }

    void push(Stack &stk, int value){
        
        if( isFull(stk) ){
            cout << "Stack Overflow!\n";
            return;
        }

        stk.array[++stk.top] = value;
    }

    int pop(Stack &stk){
        
        if(isEmpty(stk)){
            cout << "Stack Underflow!\n";
            return -1;
        }

        return stk.array[stk.top--];
    }

    int getTop(Stack stk){
        
        if (isEmpty(stk)){
            cout << "Stack is Empty!\n";
            return -1;       
        }

        return stk.array[stk.top];
    }

    int getSize(Stack stk){
        return ++stk.top;
    }










} // namespace myStackArr
