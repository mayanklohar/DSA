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
//stock span problem is to find the number of consecutive days before 
// the current day where the stock price was less than or equal to the current day's price. The above code uses a stack to keep track of the indices of the stock prices.
//  For each day, it pops elements from the stack until it finds a price greater 
// than the current day's price. 
// The span for the current day is then calculated based on the index of the 
// last higher price found in the stack.