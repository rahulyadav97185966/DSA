#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    map<T, list<pair<T, T>>> adjList;

    void addEdge(T u, T v, T weight, bool direction){
        adjList[u].push_back(make_pair(v,weight));
        if(!direction)adjList[v].push_back(make_pair(u,weight));
    }
    void printGraph(){
        for(auto i: adjList){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"["<<j.first<<","<<j.second<<"] ";
            }cout<<endl;
        }
    }
    //We need to calculate the shortest path from src distance to each node in the graph
    void shortestPath(T src){
        // indegree
        map<int, int> indegree;
        map<int, int> topoSort;
        // initialise the list with the indegree
        for(auto i: adjList){
            indegree[i.first] = 0;
        }
        //For for each v add increase indegree
        for(auto i: adjList){
            for(auto j: i.second){
                indegree[j.first]++;
            }
        }
        //take queue and push all the nodes with indegrees 0
        queue<int> q;
        for(auto i: indegree){
            if(i.second == 0){
                q.push(i.first);
            }
        }
        // Now apply the bfs
        while(!q.empty()){
            int front = q.front();
            q.pop();
            topoSort[front] = INT_MAX;
            for(auto neighbour: adjList[front]){
                indegree[neighbour.first]--;
                if(indegree[neighbour.first] == 0){
                    q.push(neighbour.first);
                }
            }
        }
        // Now we got the topo sort now we have to update that toposort.
        topoSort[src] = 0;
        for(auto i: topoSort){
            int u = i.first;
            for(auto neighbour: adjList[u]){
                if(i.second == INT_MAX)continue;
                int mini = i.second + neighbour.second;
                topoSort[neighbour.first] = min(mini, topoSort[neighbour.first]);
            }
        }
        // Now Print the toposort or we can say the distance array
        cout<<endl;
        for(auto i: topoSort){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(1,3,6,1);
    g.addEdge(1,2,2,1);
    g.addEdge(2,3,7,1);
    g.addEdge(2,4,4,1);
    g.addEdge(2,5,2,1);
    g.addEdge(3,4,-1,1);
    g.addEdge(4,5,-2,1);
    cout<<"Graph is\n";
    g.printGraph();
    cout<<endl;
    g.shortestPath(1);
    return 0;
}