#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
      public:
    Node* head;
    Node* tail;

  
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

     void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int val,int pos){
        Node *newNode = new Node(val);
        Node *temp=head;

        for(int i=0 ; i<pos-1 ; i++){
            if(temp==NULL){
                cout<<"Position is invalid\n";
                return;
            }
            temp=temp->next;    
        }
        newNode->next=temp->next;
        temp->next=newNode;

    }

    bool isCycle(Node *head){
        Node *slow=head;
        Node *fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                cout<<"cycle exists\n";
                return true;
            }
        }

        cout<<"cycle dosen't exists\n";
        return false;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n" ;
    }
};
int main(){
List ll;
ll.push_front(3);  
ll.push_front(2);  
ll.push_front(1);
ll.printList();
ll.push_back(4);
ll.insert(5,1);
ll.printList();

ll.tail->next=ll.head;
ll.isCycle(ll.head);
return 0;
}