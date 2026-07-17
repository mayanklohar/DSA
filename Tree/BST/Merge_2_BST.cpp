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

Node* BSTfromSortedVec(vector<int>& arr, int st, int end);

Node* balanceBST(Node* root){
    vector<int> nodes;
    getInorder(root , nodes);
    return BSTfromSortedVec(nodes , 0 , nodes.size()-1);
}


Node* BSTfromSortedVec(vector<int>& arr , int st , int end){
    if(st>end){
        return NULL;
    }

    int mid=(st+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=BSTfromSortedVec(arr , st , mid-1);
    root->right=BSTfromSortedVec(arr , mid+1 , end);

    return root;
}

Node* mergeBSTs(Node* root1 , Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1 , nodes1);
    getInorder(root2 , nodes2);


    int i=0 , j=0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i]<nodes2[j]){
            merged.push_back(nodes1[i]);
            i++;
        }
        else{
            merged.push_back(nodes2[j]);
            j++;
        }
    }

    while(i<nodes1.size()){
        merged.push_back(nodes1[i]);
        i++;
    }

    while(j<nodes2.size()){
        merged.push_back(nodes2[j]);
        j++;
    }

    return BSTfromSortedVec(merged , 0 , merged.size()-1);


}


int main(){
    Node* root=new Node(2);
    root->left=new Node(1);
    root->right=new Node(4);

    Node* root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);
     
    Node* mergedRoot = mergeBSTs(root, root2);

preorder(mergedRoot);
cout << endl;
    return 0;
}