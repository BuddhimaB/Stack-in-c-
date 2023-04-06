#include <iostream>
#include <vector>
using namespace std;
#include <chrono>
using namespace std::chrono;

class Stack {
public:


    Stack(int n) {
        top = -1;
        size=10;
        arr=new int [n];
    }
    void StackTop(){
        cout<<arr[top]<<endl;
    }
    int *arr;
    int size ;
    int top;
    /*
     *
     * method 1- define functions inside the class
     *
 bool isEmpty(){
     return top==-1;
 }

 bool isFull(){
     return top==9;
 }

 void push(int n){
     if(isFull()){
         cout<<"Stack is full"<<endl;
         return;
     }
     top=top+1;
     arr[top]=n;
 }
 int pop(){
     if(isEmpty()){
         cout<<"Stack is empty"<<endl;
         return 0;

     }


     cout<<arr[top]<<endl;
     return arr[top--];

 }
 void StackTop(){
     cout<<arr[top]<<endl;
 }
 void display(){
     for (int i=0;i<=top;i++){
         cout<<arr[i]<<" ";
     }
     cout<<"\n";
 }
};*/

};

////////////////////////////////   Method 2- declare functions outside the class//////////////////


 void display(Stack &s){
     cout<<"[";
     for (int i=0;i<=s.top;i++){
         cout<<s.arr[i]<<" ";
         }
     cout<<"]";
     cout<<"\n";
 }
 bool IS_EMPTY(Stack &s){
     return s.top==-1;
 }
void PUSH(Stack &s,int x){
    s.top=s.top+1;
    if(s.top>s.size){
        cout<<"Error! stack overflow"<<endl;
    }
    else{
        s.arr[s.top]=x;
    }
}
int POP(Stack &s){
    if(IS_EMPTY(s)){
        cout<<"Error! Stack is UnderFlow"<<endl;
    }
    else{
        s.top=s.top-1;
        cout<<s.arr[s.top+1]<<endl;
        return s.arr[s.top+1];
    }
}



int main() {
     int n=20;

    auto start = high_resolution_clock::now();
    Stack s(n);

    PUSH(s,23);
    PUSH(s,12);
    PUSH(s,8);
    PUSH(s,1);
    PUSH(s,2);
    PUSH(s,3);
    PUSH(s,6);
    PUSH(s,5);
    display(s);
    for(int i=0;i<5;i++){
    POP(s);}
    display(s);

    PUSH(s,100);
    PUSH(s,121);
    PUSH(s,81);
    PUSH(s,11);
    display(s);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the time taken
    cout << "Time taken by code: " << duration.count() << " microseconds" << endl;

    return 0;
}
