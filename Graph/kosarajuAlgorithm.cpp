#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T,list<T>> adjList;
    void addEdge(T u, T v, bool direction){
        adjList[u].push_back(v);
    }
    void printGraph(){
        for(auto i: adjList){
            cout<<i.first<<" ->";
            for(auto j: i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
    void dfsTS(stack<T>& st, unordered_map<int,bool>& visited, int src){
        visited[src] = 1;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour])
                dfsTS(st, visited, neighbour);
        }
        st.push(src);
    }
    void transpose(unordered_map<int, list<int>>& newAdjList){
        for(auto i: adjList){
            int u = i.first;
            for(auto v: i.second){
                newAdjList[v].push_back(u);
            }
        }
    }
    void revdfs(unordered_map<int, bool>& vis, int src, unordered_map<int, list<int>>& newAdjList){
        cout<<src<<", ";
        vis[src] = true;
        for(auto neighbhour: newAdjList[src]){
            if(!vis[neighbhour]){
                revdfs(vis, neighbhour, newAdjList);
            }
        }
    }
    void kosaraju(){
        // Step1: Apply TS using DFS
        stack<T> st;
        unordered_map<int, bool> visited;
        for(int i=0;i<4;i++){
            if(!visited[i]){
                dfsTS(st, visited, i);
            }
        }
        // Step2: Transpose the Graph
        unordered_map<int, list<int>> newAdjList;
        transpose(newAdjList);

        // Step3: Apply the DFS basis on TS
        int count = 0;
        unordered_map<int, bool> vis2;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!vis2[top]){
                count++;
                cout<<endl;
                revdfs(vis2, top, newAdjList);
            }
        }
        cout<<"\nTotal SCC are: "<<count<<endl;
    }
    
};
int main()
{
    Graph<int> g;
    g.addEdge(0,0,1);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(0,3,1);
    g.addEdge(1,0,1);
    g.addEdge(1,1,1);
    g.addEdge(1,3,1);
    g.addEdge(2,0,1);
    g.addEdge(2,1,1);
    
    g.printGraph();
    g.kosaraju();
    return 0;
}