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

    public:
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

    Node* merge(Node* left, Node* right){
        if(left == NULL) return right;
        if(right == NULL) return left;

        Node* result = NULL;

        if(left->data <= right->data){
            result = left;
            result->next = merge(left->next, right);
        }else{
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev->next = NULL;
    }
    return slow;
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

ll.splitAtMid(ll.head); 
ll.printList();
return 0;
}


 