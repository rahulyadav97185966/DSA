#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int s, int e){
    cout<<"\nPrinting array "<<"\n";
    for(int i=0;i<=e;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

void merge(int *arr, int s, int e) {
    cout<<"inside the merge, Callign the print "<<"\n";
    print(arr,s,e);

    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* left = new int[len1];
    int* right = new int[len2];

    //insert values into left and right array
    int k = s;
    for(int i=0;i<len1;i++){
        left[i] = arr[k++];
    }
    k = mid+1;
    for(int i=0;i<len2;i++){
        right[i] = arr[k++];
    }

    //merge
    int i=0;
    int j=0;
    k = s;
    while(i < len1 && j < len2) {
        if(left[i] < right[j]) {
            arr[k] = left[i++];
        }
        else {
            arr[k] = right[j++];
        }
        k++;
    }
    while(i < len1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int s, int e){

    print(arr,s,e);
    //base Case
    if(s >= e) {
        return;
    } 
    //left part sort
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main()
{
    int arr[] = {8,4,2,1};
    int size = 4;
    cout<<"Array Before Sorting is: "<<"\n";
    for(int i =0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,0,size-1);
    cout<<"\nArray After Sorting is : "<<"\n";
    for(int i =0;i<size;i++)cout<<arr[i]<<" ";
    return 0;
}
