#include<iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;

template<typename T>
class graph{

    map<T,list<T>> adjMap;
public:
    void addEdge(T u,T v,bool bidir=true){
    adjMap[u].push_back(v);
    if(bidir){
        adjMap[v].push_back(u);
    }
    }

    void print()
    {
    for(auto i:adjMap){
        cout<<i.first<<"->";
        for(auto spunk:i.second){
            cout<<spunk<<",";
        }
        cout<<endl;
    }
    }

void bfs(T src){
      queue<T> q;
      map<T,int> dist;
      map<T,T> parent;
        for(auto i:adjMap){
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T node = q.front();

            q.pop();
            for(int neighbour:adjMap[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }
        }
        //print
        for(auto i:adjMap){
            T node=i.first;
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
}

};

int main ()
{
    //graph<int> g;

    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);

    g.bfs(0);
    //g.printAdj();
    return 0;
}
