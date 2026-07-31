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

    int hashFunction(string key){
        int idx=0;

        for(int i=0 ; i<key.size() ; i++){
            idx=idx+(key[i] * key[i] % totSize);
        }
        return idx;
    }

    HashTable(int size=5){
        totSize=size;
        currSize=0;

        table=new Node*[totSize];

        for(int i=0 ; i<totSize ; i++){
            table[i]=NULL;
        }
    }

    void insert(string key , int val){
        int idx = hashFunction(key);

        Node* newNode=new Node(key,val);
        Node* head=table[idx];

        newNode->next=head;
        head=newNode;
    }
};

int main(){
    HashTable ht;
    return 0;
}
