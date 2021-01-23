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
    myStackArray<int> stak(10);

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
    
    

}


