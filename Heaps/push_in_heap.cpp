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

    cout<<"top:"<<heap.top()<<endl;
    return 0;
}