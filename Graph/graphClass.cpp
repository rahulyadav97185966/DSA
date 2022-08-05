#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T, list<T>> adjList;
    map<T, list<pair<int, int>>> adjListWeighted; // Node, list contains the connected nodei.e edge and a weight associated ith it
    //This is the graph with no weight
    void AddEdge(T u, T v, bool direction){
        adjList[u].push_back(v);

        if(direction == 0){
            adjList[v].push_back(u);
        }
    }
    void printAdj(){
        for(auto i: adjList){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    //This is for weighted graph
    void AddEdgeWeighted(T u, T v, bool direction, T weight){
        //Insert the Edge in the list
        adjListWeighted[u].push_back(make_pair(v,weight));
        //For undirected graph
        if(direction == 0){
            adjListWeighted[v].push_back(make_pair(u,weight));
        }
    }
    void printAdjWeighted(){
        for(auto i: adjListWeighted){
            cout<<i.first<<"-> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<", "<<j.second<<")"<<" ";
            }
            cout<<endl;
        }
    }

    //BFS traversal
    void bfs(int src){
        // Need queue and a visited map to see wheather something is visited
        queue<int> q;
        map<int, bool> visited;
        //push src and mark it as visited
        q.push(src);
        visited[src] = true;
        
        while (!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            
            for(auto neighbour: adjList[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        } 
    }
    //BFS for different components
    void bfsComponent(int src, map<int, bool> &visited){
        // Need queue and a visited map to see wheather something is visited
        queue<int> q;
        //push src and mark it as visited
        q.push(src);
        visited[src] = true;
        
        while (!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            
            for(auto neighbour: adjList[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        } 
    }

    //DFS of the graph
    void dfs(int src, map<int, bool>& visited){
        visited[src] = true;
        cout<<src<<" ";
        for(auto neighbour : adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour, visited);
            }
        }
    }
};
int main(){
    //Graph with no weight unweighted graph
    Graph<int> g;
    g.AddEdge(0,1,0);
    g.AddEdge(1,2,0);
    g.AddEdge(1,3,0);
    g.AddEdge(2,4,0);
    g.AddEdge(2,5,0);
    g.AddEdge(4,5,0);
    g.AddEdge(6,0,0);
    g.AddEdge(7,8,0);
    g.AddEdge(8,9,0);
    g.AddEdge(9,7,0);
    cout<<"Printing the graph"<<endl;
    g.printAdj();
    cout<<endl;
    
    // Weighted Graph (undirected)
    //Step1: Create a Graph
    Graph<int> g1;
    // Add edge between vertices
    g1.AddEdgeWeighted(0,2,0,1);
    g1.AddEdgeWeighted(2,4,0,2);
    g1.AddEdgeWeighted(2,3,0,3);
    g1.AddEdgeWeighted(4,3,0,2);
    g1.AddEdgeWeighted(3,1,0,4);
    cout<<"Prnting the weighted graph"<<endl;
    g1.printAdjWeighted();
    cout<<endl;

    //BFS Of the Graph
    cout<<"The BFS of the graph is "<<endl;
    int src = 0;
    g.bfs(src); // this will not work for the graph which has different components

    cout<<endl;
    cout<<"The bfs of differnt component "<<endl;
    map<int, bool> visited;
    for(int i=0;i<10;i++){
        if(!visited[i]){
            g.bfsComponent(i, visited);        
        }
    }

    //DFS of the Graph
    cout<<"\nThe DFS of the graph is "<<endl;
    src = 0;
    map<int, bool> visisted2;
    for(int i=0;i<10;i++){
        if(!visisted2[i]){
            g.dfs(i, visisted2);        
        }
    }
    
    return 0;
}