#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
public:
    // w -> list of (u, v);
    map<int, list<pair<int,int>>> adjList;

    void addEdge(T u, T v, T weight, bool direction){
        adjList[u].push_back(make_pair(v,weight));
        if(direction == 0){
            adjList[v].push_back(make_pair(u,weight));
        }
    }

    void printGraph(){
        for(auto i: adjList){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"["<<j.first<<","<<j.second<<"] ";
            }cout<<endl;
        }
    }
    void makeSet(vector<int>& parent, vector<int>& rank, int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(vector<int>& parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    void minimumSpanning(T n){
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent, rank, n);
        int minWeight = 0;
        for(auto i: adjList){
            for(auto j: i.second){
                int u = findParent(parent, j.first);
                int v = findParent(parent, j.second);
                if(u == v)continue;
                if(u != v){
                    minWeight += i.first;
                    unionSet(u,v,parent, rank);
                }
            }
        }
        cout<<"Ans: "<<minWeight;
    }

};
int main(){
    Graph<int> g;
    g.addEdge(4,0,1,0);
    g.addEdge(8,0,7,0);
    g.addEdge(8,1,2,0);
    g.addEdge(11,1,7,0);
    g.addEdge(2,2,8,0);
    g.addEdge(7,2,3,0);
    g.addEdge(4,2,5,0);
    g.addEdge(9,3,4,0);
    g.addEdge(14,3,5,0);
    g.addEdge(10,4,5,0);
    g.addEdge(2,5,6,0);
    g.addEdge(6,6,8,0);
    g.addEdge(1,6,7,0);
    g.addEdge(7,7,8,0);
    g.printGraph();
    cout<<"\n Krushkal's's algo\n";
    g.minimumSpanning(9);
    


}