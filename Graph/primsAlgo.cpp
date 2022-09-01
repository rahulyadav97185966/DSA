#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
public:
    // u -> list of (v, weight);
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

    void primsAlgo(T n){
        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);
        vector<int> parent(n, -1);

        // Node name, value
        //priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // let's start the algo
        key[0] = 0;
        parent[0] = -1;
        //pq.push({0, 0});
        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int u;
            // pair<int, int> top = pq.top();
            // pq.pop();
            // if(mst[top.first] == true)continue;
            // int u = top.first;

            for(int v=0;v<n;v++){
                if(mst[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }
            // mark u as true
            mst[u] = true;
            // check it's adjecent nodes
            for(auto i: adjList[u]){
                int v = i.first;
                int w = i.second;
                if(mst[v] == false && w < key[v]){
                    parent[v] = u;
                    key[v] = w;
                    //pq.push({v,w});
                }
            }
        }
        vector<pair<pair<int, int>, int>> res;
        for(int i=1;i<n;i++){
            res.push_back(make_pair(make_pair(parent[i],i), key[i]));
        }

        for(auto i: res){
            cout<<i.first.first<<"->"<<i.first.second<<" "<<i.second<<endl;
        }

    }

};
int main(){
    Graph<int> g;
    g.addEdge(0,1,4,0);
    g.addEdge(0,7,8,0);
    g.addEdge(1,2,8,0);
    g.addEdge(1,7,11,0);
    g.addEdge(2,8,2,0);
    g.addEdge(2,3,7,0);
    g.addEdge(2,5,4,0);
    g.addEdge(3,4,9,0);
    g.addEdge(3,5,14,0);
    g.addEdge(4,5,10,0);
    g.addEdge(5,6,2,0);
    g.addEdge(6,8,6,0);
    g.addEdge(6,7,1,0);
    g.addEdge(7,8,7,0);
    

    g.printGraph();
    cout<<"\nPrim's algo\n";
    g.primsAlgo(9);


}