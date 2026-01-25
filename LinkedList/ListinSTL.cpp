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
    ll.push_back(4);
   
    printList(ll);
    cout << "Size of the list: " << ll.size() << endl;
    cout << "Front element: " << ll.front() << endl;
    cout << "Back element: " << ll.back() << endl;
    printList(ll);
    ll.pop_front();
    printList(ll);

    cout<<ll.size()<<endl;
    return 0;
}