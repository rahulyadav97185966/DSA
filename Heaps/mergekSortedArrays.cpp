#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        int rows;
        int cols;
    node(int d, int row, int col){
        this->data = d;
        rows = row;
        cols = col;
    }
};
class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};
vector<int> mergekSortedArrays(vector<vector<int>> &arrays, int k){
    priority_queue<node*, vector<node*>, compare> minHeap;

    //step1 : insert first element to minheap of all arrays
    for(int i=0;i<k;i++){
        node* temp = new node(arrays[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;
    //step2: 
    while(minHeap.size() >= 1){
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->rows;
        int j = temp->cols;

        if(j+1 < arrays[i].size()){
            node* next = new node(arrays[i][j+1], i , j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int k = 3;
    vector<vector<int>> arrays;
    for(int i=0;i<k;i++){
        vector<int> arr;
        for(int j=0;j<4;j++){
            int in;
            cin>>in;
            arr.push_back(in);
        }
        arrays.push_back(arr);
    }
    vector<int> ans = mergekSortedArrays(arrays, k);
    for(auto i : ans)cout<<i<<" ";
    return 0;
}
