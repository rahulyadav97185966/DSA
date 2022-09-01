#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
            adjList[v].push_back(u);
    }
    void printgraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    vector<int> shortestPath(int src, int dest)
    {
        queue<T> q;
        map<int, bool> visited;
        map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto neighbhour : adjList[front])
            {
                if (!visited[neighbhour])
                {
                    q.push(neighbhour);
                    visited[neighbhour] = true;
                    parent[neighbhour] = front;
                }
            }
        }
        vector<int> ans;
        ans.push_back(dest);
        while (parent[dest] != src)
        {
            ans.push_back(parent[dest]);
            dest = parent[dest];
        }
        ans.push_back(src);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(3, 8, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(6, 7, 0);
    g.addEdge(5, 8, 0);
    g.addEdge(7, 8, 0);
    g.printgraph();
    cout << endl;
    vector<int> ans = g.shortestPath(1, 8);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}