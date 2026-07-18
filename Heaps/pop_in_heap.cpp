#include<iostream>
#include<queue>
using namespace std;

class Heap{
    vector<int> vec;
    public:

    void push(int val){

        vec.push_back(val);

        //fix heap

        int x=vec.size()-1;
        int partI=(x-1)/2;

        while(partI>=0 && vec[x]>vec[partI]){
            swap(vec[x] , vec[partI]);
            x=partI;
            partI=(x-1)/2;
        }
    }

    void heapify(int i){
        if(i>=vec.size()){
            return;
        }

        int l=2*i+1;
        int r=2*i+2;

        int maxIdx=i;

        if(l<vec.size() && vec[l]>vec[maxIdx]){
            maxIdx=l;
        }

        if(r<vec.size() && vec[r]>vec[maxIdx]){
            maxIdx=r;
        }

        swap(vec[i] , vec[maxIdx]);

        if(maxIdx!=i){
            //swapping with child node
            heapify(maxIdx);
        }
    }

    void pop(){

        //1
        swap(vec[0] , vec[vec.size()-1]);
        //2
        vec.pop_back();
        //3
        heapify(0);
    }

    int top(){
        return vec[0];
    }

    bool isEmpty(){
        return vec.size()==0;
    }
};

int main(){
    Heap heap;

    heap.push(50);
    heap.push(10);
    heap.push(100);

    while(!heap.isEmpty()){
        cout<<"top:"<<heap.top()<<endl;
        heap.pop();
    }
    
    
    return 0;
}