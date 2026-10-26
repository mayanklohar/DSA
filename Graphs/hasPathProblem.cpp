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

  

void dfsHelper(int u  , vector<bool> &vis){
    cout<<"vertex:"<<u<<endl;
    vis[u]=true;

    list<int> neighbors=l[u];
    for(int v:neighbors){
        if(!vis[v]){
            dfsHelper(v,vis);
        }
    }
}

bool hasPath(int src, int dest){
    vector<bool> vis(V,false);
    return pathHelper(src, dest, vis);
}

bool pathHelper(int src, int dest, vector<bool> &vis){
    if(src == dest){
        return true;
    }
    vis[src] = true;
    list<int> neighbors = l[src];
    for(int v : neighbors){
        if(!vis[v]){
            if(pathHelper(v, dest, vis)){
                return true;
            }
        }
    }
    return false;
}
};

    int main(){
        Graph graph(5);

        graph.addEdge(0,1);
        graph.addEdge(1,2);
        graph.addEdge(1,3);
        graph.addEdge(2,3);
        graph.addEdge(2,4);
        graph.hasPath(0, 4) ? cout << "Path exists for 0 to 4" << endl : cout << "No path" << endl;

        return 0;
    }
