#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
     Node(int data){
        this->data=data;
        left=right=NULL;
     }
};

Node* insert(Node* root , int val){
    if(root==NULL){
        root = new Node(val);
        return root;    
    }

    if(val<root->data){
        root->left=insert(root->left , val);
    }
    else{
        root->right=insert(root->right , val);
    }

    return root;
}

Node* buildBST(int arr[] , int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
        return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printInRange(Node* root , int start , int end){
    if(root==NULL){
        return;
    }

    if(start<=root->data && root->data<=end){
        printInRange(root->left , start , end);
        cout<<root->data<<" ";
        printInRange(root->right , start , end);
    }
    else if(root->data<start){
        printInRange(root->right , start , end);
    }
    else{
        printInRange(root->left , start , end);
    }
}

int main(){
    int arr[]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
   
    printInRange(root , 5 , 12);
    cout<<endl;
    return 0;
}