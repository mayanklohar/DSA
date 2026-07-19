#include<iostream>
#include<queue>
#include<vector>
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

class Student{
    public:
    string name;
    int marks;

    Student(string name , int marks){
        this->name=name;
        this->marks=marks;
    }

    bool operator < (const Student &obj) const{
        return this->marks<obj.marks;
    }
};

int main(){
 
    priority_queue<Student> pq;

    pq.push(Student("A" , 100));
    pq.push(Student("B" , 10));
    pq.push(Student("C" , 50));
    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
    
    
    return 0;
}