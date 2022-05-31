
#include <iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    
    int len1 = mid-s+1;
    int len2 = e-mid;
    //create left and right array and assigning size
    int* left = new int[len1];
    int* right = new int[len2];
    
    //copying to left and right array
    int original_size = s;
    for(int i=0;i<len1;i++) {
        left[i] = arr[original_size++];
    }
    original_size = mid+1;
    for(int i=0;i<len2;i++){
      right[i] = arr[original_size++];  
    } 
    
    int i=0;
    int j=0;
    int k=s;
    while(i < len1 && j < len2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            k++;
            i++;
        }
        else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i < len1){
        arr[k] = left[i];
        i++;k++;
    }
    while(j < len2){
        arr[k] = right[j];
        j++;k++;
    }
}

void mergeSort(int arr[], int s, int e){
    if(s >= e)return;
    int mid = (s+e)/2;
    //left part sort
    mergeSort(arr, s, mid);
    //right part sort
    mergeSort(arr, mid+1, e);
    //mergetwo sorted parts;
    merge(arr,s,e);
}

int main()
{
    int arr[] = {6,9,11,12,2,3,5,7};
    int size = 8;
    mergeSort(arr,0,size-1);
    for(int i =0;i<size;i++)cout<<arr[i]<<" ";
    return 0;
}
