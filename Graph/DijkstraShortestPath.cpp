#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, T>>> adjList;

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
    vector<T> shortestPath(T src, T n){
        vector<T> dist(n,INT_MAX);
        // pair : dist, node
        set<pair<T, T>> st;
        //initial step
        dist[src] = 0;
        st.insert(make_pair(0,src));

        while(!st.empty()){
            //top element
            auto top = *(st.begin());
            //pop element
            st.erase(st.begin());
            T dist1 = top.first;
            T node = top.second;
            for(auto neighbhour: adjList[node]){
                //neoghbhpur.first = neighbhour name
                //neighbhour.second = neighbhour weight
                T total_dist = neighbhour.second + dist1;
                if(total_dist < dist[neighbhour.first]){
                    //remove old record first if there
                    auto record = st.find(make_pair(dist[neighbhour.first], neighbhour.first));
                    //if record found, then erase
                    if(record != st.end()){
                        st.erase(record);
                    }
                    //update dist of the node
                    dist[neighbhour.first] = neighbhour.second + dist1;
                    //insert into the set then
                    st.insert(make_pair(dist[neighbhour.first], neighbhour.first));
                }
            }
        }
        return dist;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1,5,0);
    g.addEdge(0,2,8,0);
    g.addEdge(1,3,2,0);
    g.addEdge(1,2,9,0);
    g.addEdge(2,3,6,0);

    cout<<"Graph is\n";
    g.printGraph();
    cout<<endl;
    vector<int> ans = g.shortestPath(0,4);
    cout<<endl;
    for(auto i: ans)cout<<i<<" ";
    return 0;
}