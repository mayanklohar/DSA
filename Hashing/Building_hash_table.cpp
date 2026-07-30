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

class HashTable{
    public:
    int totSize;
    int currSize;
    Node** table;

    HashTable(int size=5){
        totSize=size;
        currSize=0;

        table=new Node*[totSize];

        for(int i=0 ; i<totSize ; i++){
            table[i]=NULL;
        }
    }
};

int main(){
    HashTable ht;
    return 0;
}
