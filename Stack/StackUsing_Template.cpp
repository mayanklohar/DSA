#include<iostream>
#include<vector>
#include<string>    
using namespace std;

template<class T>

class Stack{
    vector<T>vec;
    public:
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        vec.pop_back();
    
    }

    T top(){
        
        int lastIdx=vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size()==0;   
    }
};


    int main(){
        // Stack <char>s;
        // s.push('c');
        // s.push('b');
        // s.push('a');

        Stack <string>s;
        s.push("may");
        s.push("june");
        s.push("july");
        
        while(!s.isEmpty()){
            cout<<s.top()<<endl;
            s.pop();
        }
        cout<<"Stack is now empty\n";
        
       
    }

    //we do not write datatypes in stack<char> s;
    //  because we have used template and we can use any datatype we want.
