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

    ~Node(){
if(next != NULL){
            delete next;
            next = NULL;
        }   
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
      Node*  newNode = new Node(val);
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

    int searchItr(int key){
        Node * temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
              
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    
    void pop_front(){
        if(head == NULL){
            cout<<"LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;  
        temp->next = NULL;
        delete temp;
    }

int helper(Node* h, int key) {
    if (h == NULL) {
        return -1;
    }

    if (h->data == key) {
        return 0;
    }

    int idx = helper(h->next, key);
    if (idx == -1) {
        return -1;
    }

    return idx + 1;
}

int searchRec(int key) {
    return helper(head, key);
}


    ~List(){

        cout<<"~List\n";
        if(head != NULL){
            delete head;
            head = NULL;
        }   
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
 cout<<ll.searchRec(4)<<endl;

return 0;
}