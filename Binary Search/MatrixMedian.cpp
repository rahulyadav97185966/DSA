#include<bits/stdc++.h>
using namespace std;


int SearchElement(vector<vector<int>> &matrix){
    vector<int> v;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++) {
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(), v.end());
    if(v.size() % 2 == 1){
        int index = v.size() / 2;
        return v[index];
    }
    else{
        int index = v.size()/2;
        return (v[index]+v[index-1])/2;
    }
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    SearchElement(matrix);
}


int main(){
    int n,m;
    cin>>n>>m;
    int* arr = new int[n];
    
    delete []arr;
    return 0;
}