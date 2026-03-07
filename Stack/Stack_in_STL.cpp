#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"top element: "<<s.top()<<endl; // 4

    
    cout<<"stack size: "<<s.size()<<endl; // 3
    s.pop();
    cout<<"element poped"<<endl;
    cout<<s.top()<<endl; // 2
    cout<<"stack size: "<<s.size()<<endl; // 2

    return 0;
}