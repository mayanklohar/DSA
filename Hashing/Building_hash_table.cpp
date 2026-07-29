#include<iostream>
using namespace std;

class Node{
    public:

    string key;
    int val;
    Node* next;

    Node(string key , int val){
        this->key=key;
        this->val=val;
        next=NULL;

    }
};

int main(){
    return 0;
}
