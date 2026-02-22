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
    // Output: 5 25 25 -1
    // Explanation:
    // For 4, the next greater element is 5.
    // For 5, the next greater element is 25.
    // For 2, the next greater element is 25.
    // For 25, there is no greater element to the right, so we print -

    return 0;
}