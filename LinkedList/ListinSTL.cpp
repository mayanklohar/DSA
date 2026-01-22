#include<iostream>
#include<list>
#include<iterator>
using namespace std;


 void printList(list<int> &ll){
 list<int> :: iterator itr;

 for(itr = ll.begin(); itr != ll.end(); itr++){
     cout << *itr << "->";
 }
 cout << "NULL\n";
}
 
int main()
{
    list<int> ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    printList(ll);
    return 0;
}