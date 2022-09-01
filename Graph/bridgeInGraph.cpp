#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    map<int, list<int>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }
    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << " : ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    // Function for finding bridge
    void dfs(int node, unordered_map<int, bool> &visited, vector<int> &desc, vector<int> &low, int parent, int timer)
    {
        timer++;
        visited[node] = true;
        desc[node] = timer;
        low[node] = timer;

        for(auto neighbhour: adjList[node]){
            if(parent == neighbhour)continue;
            if(!visited[neighbhour]){
                dfs(neighbhour, visited,desc,low,node,timer);
                // Low update : this means child is making the backedge so updating the parent
                low[node] = min(low[node], low[neighbhour]);
                // check for the bridge
                if(low[neighbhour] > desc[node]){
                    cout<<"Bridge Present";
                    return;
                }
            }
            else{
                low[node] = min(low[node], desc[neighbhour]);
            }
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(3, 4, 0);

    // Found Bridge in a graph
    unordered_map<int, bool> visited;
    vector<int> desc(5, -1);
    vector<int> low(5, -1);
    int parent = -1;
    int timer = 0;

    for (int i = 0; i < 5; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, desc, low, parent, timer);
        }
    }

    return 0;
}