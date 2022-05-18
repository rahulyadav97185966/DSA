#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[4][4], int row, int col, int target){
    int start = 0;
    int end = col-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[row][mid] == target) return true;
        if(arr[row][mid] > target){
            end = mid-1;
        }
        if(arr[row][mid] < target){
            start = mid+1;
        }
    }
    return false;
}

bool  findRow(int arr[4][4], int n, int m, int target){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid][0] == target || arr[mid][m-1] == target){
            return true;
        }
        //cout<<arr[mid][0]<<" "<<arr[mid][m-1];
        if(target > arr[mid][0] && target < arr[mid][m-1]){
            return binarySearch(arr, mid , m, target);
        }
        if(target < arr[mid][0]){
            end = mid-1;
        }
        if(target > arr[mid][m-1]){
            start = mid+1;
        }
    }
    return false;
}
int main()
{
    int arr[4][4] = {{0, 6, 8, 9},
                    {20, 22, 28, 29},
                    {36, 38, 50, 61},
                    {64, 66, 100, 122}};

    cout<<findRow(arr, 4, 4, 50);
    return 0;
}
