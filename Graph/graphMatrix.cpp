#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    T** arr;
    int n;
    Graph(int n){
        this->n = n;
        arr = new T*[n];
        for(int i=0;i<n;i++){
            arr[i] = new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = 0;
            }
        }
    }

    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void addEdge(int u, int v, bool direction){
        arr[u][v] = 1;
        if(direction == 0){
            arr[v][u] = 1;
        }
    }

    //bfs of the graph
    void bfs(int src){
        queue<int> q;
        q.push(src);
        map<int, bool> visited;
        visited[src] = 1;
        while(!q.empty()){
            int front = q.front();
            cout<<front<<" ";
            q.pop();
            for(int i=0;i<n;i++){
                if(arr[front][i] == 1 && visited[i] == 0){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    //DFS of the graph
    void dfs(int src, map<int, bool>& visited){
        visited[src] = true;
        cout<<src<<" ";

        for(int i=0;i<n;i++){
            if(arr[src][i] == 1 && visited[i] == 0){
                dfs(i, visited);

            }
        }
    }
};
int main(){

    Graph<int> g(7);
    g.addEdge(0,1,0);
    g.addEdge(0,6,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(2,5,0);
    g.addEdge(4,5,0);
    cout<<"Print the Graph"<<endl;
    g.print();
    cout<<"Printing the BFS"<<endl;
    g.bfs(0);
    cout<<"\nPrinting the DFS"<<endl;
    map<int, bool> visited;
    g.dfs(0, visited);
    return 0;
}