#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stockSpanProblem(vector<int> stock , vector<int> span){
    stack<int> st;
    st.push(0);
    span[0] = 1;
    for(int i=1 ; i<stock.size() ; i++){
        int currPrice = stock[i];
        while(!st.empty() && currPrice > stock[st.top()]){
            st.pop();
        }
        if(st.empty()){
            span[i] = i+1;
        }
        else{
            int prevHigh = st.top();
            span[i] = i - prevHigh;
        }
    }
    for(int i=0 ; i<span.size() ; i++){
        cout<<span[i]<<" ";
    }
}
// Time Complexity : O(n)
int main(){
vector<int> stock = {100, 80, 60, 70, 60, 75, 85};

vector<int> span={0,0,0,0,0,0,0};
stockSpanProblem(stock , span);
}