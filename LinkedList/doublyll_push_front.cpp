#include <iodstream>
using namespace std;    

class Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
         prev = next= NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node *newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
    }

    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" <=>";
            temp = temp->next;
        }
        cout<<" NULL\n";
    }
};

int main(){
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printList();

    return 0;
}