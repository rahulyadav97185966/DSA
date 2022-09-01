#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
public:
    map<T, list<T>> adjList;
    //Add an edge and create adjList or graph
    void addEdge(T u, T v, bool direction){
        adjList[u].push_back(v);
        if(direction == 0){
            adjList[v].push_back(u);
        }
    }
    //Print the Graph
    void printGraph(){
        for(auto i : adjList){
            cout<<i.first<<" ->";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    //check Cycle in undirected graph
    bool checkCycleUsingBFS(T src){
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        map<T, T> parent;
        parent[src] = -1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour: adjList[front]){
                cout<<neighbour<<" "<<parent[front]<<"\n";
                if(visited[neighbour] == true && neighbour != parent[front]){
                    return true;
                }
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=1;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }
    //Using DFS
    bool dfsCycle(T src, map<T, bool> &visited, T parent){
        visited[src] = true;
        for(auto neigbour: adjList[src]){
            if(!visited[neigbour]){
                bool cycleDetected = dfsCycle(neigbour, visited, src);
                if(cycleDetected == true)return true;
            }
            else if(visited[neigbour] == true && neigbour != parent){
                //cycle is present
                return true;
            }
        }
        return false;
    }
};  

int main(){
    Graph<int> g;
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(3,5,0);
    g.addEdge(4,6,0);
    g.addEdge(5,6,0);
    g.addEdge(6,7,0);
    g.printGraph();
    cout<<"\nCycle is "<<g.checkCycleUsingBFS(1);
    map<int, bool> visited;
    int parent = -1;
    cout<<"\nCycle is "<<g.dfsCycle(1, visited, parent);
    return 0;
}