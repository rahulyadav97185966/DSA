#include<bits/stdc++.h>
using namespace std;
class heap{
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
        while (index > 1)
        {
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
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete";
            return;
        }
        else{
            arr[1] = arr[size];
            size = size-1;
            //take root node to it's correct position
            int i = 1;

            while(i < size){
                int largest = i;
                int leftchild = 2*i;
                int rightchild =  (2*i)+1;

                if(leftchild <= size && arr[leftchild] > arr[largest]){
                    largest = leftchild;
                }
                if(rightchild <= size && arr[rightchild] > arr[largest]){
                    largest = rightchild;
                }

                if(largest != i){
                    swap(arr[i], arr[largest]);
                    i = largest;
                }
                else{
                    break;
                }
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
// Heapify Algorithm
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
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
        //step1: swap
        swap(arr[size], arr[1]);
        size--;
        //step2: call heaify
        heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(50);
    h.insert(51);
    h.insert(49);
    h.print();

    h.deleteFromHeap();
    h.print();
    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5;
    // for(int i=n/2;i>0;i--){
    //     heapify(arr, n, i);
    // }
    // cout<<"printing the array\n";
    // for(int i=0;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";

    // cout<<"heap sort is \n";
    // HeapSort(arr, n);
    // for(int i=0;i<=n;i++)cout<<arr[i]<<" ";


    // cout<<"\nusing priority queue\n";
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);
    // pq.pop();
    // cout<<pq.top()<<endl;

    // //min heap
    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // minHeap.push(4);
    // minHeap.push(2);
    // minHeap.push(5);
    // minHeap.push(3);
    // cout<<minHeap.top();

    return 0;
}