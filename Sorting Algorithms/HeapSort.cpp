#include<bits/stdc++.h>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        //step1 : put first element to the last index
        arr[1] = arr[size];
        // step 2: reduce the size of array
        size--;
        // Step 3: take root node to it's correct position

        int i=1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i +1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size &&  arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void Print() {
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
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

void HeapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        // step1: swap
        swap(arr[size],arr[1]);
        size--;

        // step2: 
        heapify(arr, size, 1);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    heap h;
    for(int i=0;i<n;i++){
        h.insert(arr[i]);
    }
    h.Print();
    h.deletion();
    h.Print();

    cout<<"\nthis is for heapify"<<endl;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }    
    cout<<"printing array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    HeapSort(arr,n);
    cout<<"soring"<<endl;

    return 0;
}