#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    map<int, list<pair<int, int>>> adjList;

    void addEdge(T u, T v, T weight, bool direction){
        adjList[u].push_back(make_pair(v, weight));
        if(direction == 0)adjList[v].push_back(make_pair(u, weight));
    }
    void printGraph(){
        for(auto i: adjList){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"["<<j.first<<", "<<j.second<<"]";
            }cout<<endl;
        }
    }
    void Algo(T src, T n){
        map<int, int> distance_array;
        // Initialise the array
        for(int i=1;i<=n;i++){
            distance_array[i] = INT_MAX;
        }
        // Apply formula n-1 times
        distance_array[src] = 0;
        for(int k=1;k<n;k++){
            for(auto i: adjList){
                for(auto j: i.second){
                    cout<<"nodes are: "<<i.first<<" "<<j.first<<" "<<j.second<<endl;
                    cout<<"sum is: "<<distance_array[i.first]+j.second<<" "<<distance_array[j.first]<<endl;
                    if(distance_array[i.first] == INT_MAX)continue;
                    if(distance_array[i.first]+j.second < distance_array[j.first]){
                        distance_array[j.first] = distance_array[i.first]+j.second;
                    }
                }
            }
        }
        // Apply Formula last time
        bool anychange = false;
        for(auto i: adjList){
            for(auto j: i.second){
                if(distance_array[i.first] == INT_MAX)continue;
                if(distance_array[i.first]+j.second < distance_array[j.first]){
                    anychange = true;
                    distance_array[j.first] = distance_array[i.first]+j.second;
                }
            }
        }
        if(anychange){
            cout<<"negative cycle present"<<endl;
            return;
        }
        else{
            for(auto i: distance_array){
                cout<<i.first<<" "<<i.second<<endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,3,2,1);
    g.addEdge(1,2,2,1);
    g.addEdge(2,3,-1,1);
    g.Algo(1,3);
    return 0;
}