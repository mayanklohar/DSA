#include<iostream>
#include<vector>
#include <climits>
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

class Info{
    public:

    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST , int min , int max , int sz){
        this->isBST=isBST;
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};

static int maxSize=0;

Info* largestBST(Node* root){
  if(root==NULL){
    return new Info(true, INT_MAX, INT_MIN, 0);
}

    if(root->left==NULL && root->right==NULL){
        return new Info(true , root->data , root->data , 1);
    }

    Info* leftInfo=largestBST(root->left);
    Info* rightInfo=largestBST(root->right);

    int currMin=min(root->data , min(leftInfo->min , rightInfo->min));
    int currMax=max(root->data , max(leftInfo->max , rightInfo->max));
    int currSz=leftInfo->sz + rightInfo->sz + 1;

    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min){
        maxSize=max(maxSize , currSz);
        return new Info(true , currMin , currMax , currSz);
    }

    return new Info(false , currMin , currMax , max(leftInfo->sz , rightInfo->sz));
}

Node* BSTfromSortedVec(vector<int>& arr , int st , int end){
    if(st>end){
        return NULL;
    }

    int mid=(st+end)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=BSTfromSortedVec(arr , st , mid-1);
    curr->right=BSTfromSortedVec(arr , mid+1 , end);

    return curr;
}

void getInorder(Node* root , vector<int>& nodes){
    if(root==NULL){
        return;
    }

    getInorder(root->left , nodes);
    nodes.push_back(root->data);
    getInorder(root->right , nodes);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* balanceBST(Node* root){
    vector<int> nodes;
    getInorder(root , nodes);
    return BSTfromSortedVec(nodes , 0 , nodes.size()-1);
}

int main(){
    Node* root=new Node(50);
    root->left=new Node(30);
    root->left->left=new Node(5);
    root->left->left->left=new Node(20);

    root->right=new Node(60);
    root->right->right=new Node(70);
    root->right->right->right=new Node(90);


  largestBST(root);
cout << "Size of largest BST in BT is : " << maxSize << endl;

    cout<<endl;

    return 0;
}