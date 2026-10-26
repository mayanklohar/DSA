#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v){
        V=v;
        l=new list<int>[V];

    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0 ; u<V ; u++){
            list<int> neighbors=l[u];
            cout<<"Vertex "<<u<<"->";
            for(int v : neighbors){
                cout<<v<<",";
            }   
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(V,false);

        q.push(0);
        vis[0]=true;

        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<"vertex:"<<u<<endl;

            list<int> neighbors=l[u];
            for(int v:neighbors){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

    int main(){
        Graph graph(5);

        graph.addEdge(0,1);
        graph.addEdge(1,2);
        graph.addEdge(1,3);
        graph.addEdge(2,3);
        graph.addEdge(2,4);
        graph.bfs();

        return 0;
    }
