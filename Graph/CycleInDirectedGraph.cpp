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
    //Using DFS
    bool dfsCycle(T src, map<T, bool> &visited, map<T, bool>& dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                bool cycle = dfsCycle(neighbour, visited, dfsVisited);
                if(cycle)return true;
            }      
            else if(dfsVisited[neighbour] == true)return true;
        }
        dfsVisited[src] = false;
        return false;
    }
    //using kahn's Algorithm
    bool dfsKahn(T src){
        // Step1: Setup the indegree
        map<T, T> indegree;
        for(auto i: adjList){
            indegree[i.first] = 0;
        }
        for(auto i: adjList){
            for(auto j: i.second){
                indegree[j]++;
            }
        }
        int n = indegree.size();
        // Take queue and push the elements who has indegree 0;
        queue<T> q;
        for(auto i: indegree){
            if(i.second == 0){
                q.push(i.first);
            }
        }
        // Apply BFS Now
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(auto neighbhour: adjList[front]){
                indegree[neighbhour]--;
                if(indegree[neighbhour] == 0){
                    q.push(neighbhour);
                }
            }
        }
        if(cnt == n){
            //cout<<"No Cycle in the graph"<<endl;
            return false;
        }
        else{
            //cout<<"graph has cycle"<<endl;
            return true;
        }
    }
};  

int main(){
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(2,4,1);
    g.addEdge(3,7,1);
    g.addEdge(3,8,1);
    g.addEdge(8,7,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);


    g.printGraph();
    map<int, bool> visited;
    map<int, bool> dfsVisited;
    
    cout<<"\nCycle is "<<g.dfsCycle(1, visited, dfsVisited)<<endl;
    cout<<"\nCycle is "<<g.dfsKahn(1);
    return 0;
}