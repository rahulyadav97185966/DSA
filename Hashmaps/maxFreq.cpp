#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10] = {3,4,2,1,6,3,3,2,3,2};
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;
    for(int i=0;i<10;i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0;i<10;i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    cout<<"Answer is "<<maxAns;
    return 0;
}