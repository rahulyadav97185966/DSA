#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction){
        adjList[u].push_back(v);

        if(direction==0)adjList[v].push_back(u);
    }
    void printgraph(){
        for(auto i: adjList){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    //Using the Kahn's Algorithm
    void TopoSortKahn(){
        // Step1: calculate indegree 
        map<T, T> indegree;
        //initialise with indegree 0
        for(auto i : adjList){
            indegree[i.first] = 0;
        }
        for(auto i: adjList){
            for(auto j: i.second){
                indegree[j]++;
            }
        }
        // Step2: Apply BFS in queue insert the node with zero indegree
        queue<T> q;
        for(auto i: indegree){
            if(i.second == 0){
                q.push(i.first);
            }
        }
        //step3: BFS
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cout<<front<<" ";
            for(auto neibhour: adjList[front]){
                indegree[neibhour]--;
                if(indegree[neibhour] == 0){
                    q.push(neibhour);
                }
            }
        }
    }
    //using the DFS
    void TopoSortDFS(T src, stack<int>& stk, map<int,bool>& visited){
        visited[src] = true;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                TopoSortDFS(neighbour, stk, visited);
            }
        }
        stk.push(src);
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,5,1);
    g.addEdge(3,5,1);
    g.addEdge(5,4,1);
    g.printgraph();
    //Print Topological Sort Using Kahn's Algo
    cout<<"\nTOPo Sort is \n";
    g.TopoSortKahn();
    // Printing the topo sort using the DFS
    cout<<endl;
    map<int, bool> visited;
    stack<int> stk;
    g.TopoSortDFS(1,stk, visited);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}