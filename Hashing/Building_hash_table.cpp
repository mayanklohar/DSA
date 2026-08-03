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

    ~Node(){
        if(next!=NULL){
            delete next;
        }
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
        return idx% totSize;
    }

    void rehash(){
        Node** oldTable=table;
        int oldSize=totSize;

        totSize=2*totSize;
        currSize=0;
        table=new Node*[totSize];

        for(int i=0 ; i<totSize ; i++){
            table[i]=NULL;
        }

        for(int i=0 ; i<oldSize ; i++){
            Node* temp=oldTable[i];

            while(temp!=NULL){
                insert(temp->key , temp->val);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }

        }

        delete [] oldTable;
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

        newNode->next=table[idx];
        table[idx]=newNode;

        currSize++;

        double lambda=currSize/(double)totSize;
        if(lambda>1){
            rehash();
        }
    }

    bool exists(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];

        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return false;
    }

    int search(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];

        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
};

int main(){
    HashTable ht;

    ht.insert("India" , 100);
    ht.insert("China" , 150);
    ht.insert("USA" , 200);
    ht.insert("UK" , 250);
    ht.insert("Germany" , 300);
    if(ht.exists("India")){
        cout<<"India is present with value "<<ht.search("India")<<endl;
    }
    else{
        cout<<"India is not present"<<endl;
    }
    return 0;
}
