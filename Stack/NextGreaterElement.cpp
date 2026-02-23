#include<iostream>
#include<stack>
using namespace std;

void nextGreater(int arr[], int n) {
    stack<int> s;

    for(int i = n-1; i >= 0; i--) {

        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if(s.empty())
            cout << "-1 ";
        else
            cout << s.top() << " ";

        s.push(arr[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = 4;

    nextGreater(arr, n);
  
    
    return 0;
}