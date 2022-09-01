#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    map<T, list<T>> adjlist;
    //Graph with weight 
    map<T, list<pair<T, T>>> adjListWeighted;
    //Graph without weight
    void addEdge(T u, T v, bool direction)
    {
        adjlist[u].push_back(v);
        if (direction == 0){
            adjlist[v].push_back(u);
        }
    }
    void printList()
    {
        for(auto i : adjlist){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    //BFS Of the Graph
    void bfs(T src){
        queue<int> q;
        map<int, bool> visited;
        visited[src] = true;
        q.push(src);
        while (!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            for(auto i: adjlist[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
            
        }
        
    }
    //bfs with different component
    void bfsComponent(T src, map<int, bool> &visited){
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while (!q.empty())
        {
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            for(auto i: adjlist[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    //DFS Of the graph
    void dfs(T src, map<int, bool> &visited){
        visited[src] = 1;
        cout<<src<<" ";
        for(auto neighbour: adjlist[src]){
            if(!visited[neighbour])
                dfs(neighbour, visited);
        }

    }
    //Graph With the weight
    void addEdgeWeight(T u, T v, T weight, bool direction){
        adjListWeighted[u].push_back(make_pair(v,weight));
        if(direction == 0){
            adjListWeighted[v].push_back(make_pair(u,weight));
        }
    }
    void printListWeighted(){
        for(auto i : adjListWeighted){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<"("<<j.first<<", "<<j.second<<") ";
            }
            cout<<endl;
        }
    }
    void bfsWeighted(T src){
        queue<int> q;
        map<int, bool> visited;
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            for(auto i : adjListWeighted[front]){
                if(!visited[i.first]){
                    q.push(i.first);
                    visited[i.first] = 1;
                }
            }
        }
    }
};
template<typename T1>
class GraphMatrix{
public:
    T1 n;
    T1 **arr;
    GraphMatrix(T1 n){
        this->n = n;
        this->arr = new T1*[n];
        for(T1 i=0;i<n;i++){
            arr[i] = new T1[n];
        }
        for(T1 i=0;i<n;i++){
            for(T1 j=0;j<n;j++){
                arr[i][j] = 0;
            }
        }
    }
    void addEdge(T1 u, T1 v, bool direction){
        arr[u][v] = 1;
        if(!direction)arr[v][u] = 1;
    }
    void printGraph(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    cout<<"Graph without weights"<<endl;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 8, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(2, 6, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(10, 11, 0);
    g.addEdge(10, 12, 0);
    cout<<"Printing the graph"<<endl;
    g.printList();
    cout<<"\nBFS of the graph is unweighted\n";
    g.bfs(1);
    cout<<endl;
    //If Different Component Then We need to pass the bfs from here only
    map<int, bool> visited;
    vector<int> myarr = {1,2,4,5,6,8,10,11};
    for(int i=0;i<myarr.size();i++){
        if(!visited[myarr[i]])g.bfsComponent(myarr[i], visited);
    }
    cout<<endl;
    cout<<"dfs of the graphs is "<<endl;
    visited.clear();
    for(int i=0;i<myarr.size();i++){
        if(!visited[myarr[i]])g.dfs(myarr[i], visited);
    }
    cout<<endl;

    cout<<"Graph with Weights"<<endl;
    g.addEdgeWeight(1,2,10,0);
    g.addEdgeWeight(1, 8, 20, 0);
    g.addEdgeWeight(2, 4, 16, 0);
    g.addEdgeWeight(2, 6, 14, 0);
    g.addEdgeWeight(4, 5, 18, 0);
    cout<<"Printing the weighted graph"<<endl;
    g.printListWeighted();
    cout<<"\nBFS of the graph is weighted\n";
    g.bfsWeighted(1);
    cout<<endl;
    /* Graph Using Matrix */
    GraphMatrix<int> g1(6);
    g1.addEdge(0, 1, 0);
    g1.addEdge(1, 3, 0);
    g1.addEdge(3, 4, 0);
    g1.addEdge(4, 5, 0);
    g1.addEdge(5, 1, 0);
    cout<<"printing the adj matrix"<<endl;
    g1.printGraph();


    return 0;
}