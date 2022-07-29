#include<bits/stdc++.h>
using namespace std;

// Heapify Algorithm
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main(){
    vector<int> maxHeap1 = {10, 5, 6, 2};
    vector<int> maxHeap2 = {12, 7, 9};

    //Merge two vectors
    vector<int> ans;
    for(auto i : maxHeap1){
        ans.push_back(i);
    }
    for(auto i : maxHeap2){
        ans.push_back(i);
    }
    for(int i=ans.size()/2-1;i>=0;i--){
        heapify(ans, ans.size(), i);
    }

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}