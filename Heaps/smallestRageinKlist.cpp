#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int rows;
    int cols;
    node(int d, int row, int col)
    {
        this->data = d;
        this->rows = row;
        this->cols = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
int SmallestRange(vector<vector<int>> &arrays, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;
    // step1 : insert first element to minheap of all arrays
    for (int i = 0; i < k; i++)
    {
        node *ele = new node(arrays[i][0], i, 0);
        mini = min(mini, ele->data);
        maxi = max(maxi, ele->data);
        minHeap.push(ele);
    }
    int start = mini, end = maxi;
    // step2: prcess the ranges
    while (!minHeap.empty())
    {
        //fetch mini
        node *temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        //update range
        if (maxi-mini < end-start)
        {
            start = mini;
            end = maxi;
        }
        //checking next elemtne and pushing
        if (temp->cols+1 < n)
        {
            maxi = max(maxi, arrays[temp->rows][temp->cols + 1]);
            minHeap.push(new node(arrays[temp->rows][temp->cols + 1], temp->rows, temp->cols + 1));
        }
        else
        {
            //next does not exist
            break;
        }
    }
    //returing different between end and start
    return end-start+1;
}
int main(int argc, char const *argv[])
{
    int k = 3;
    vector<vector<int>> arrays;
    for (int i = 0; i < k; i++)
    {
        vector<int> arr;
        for (int j = 0; j < 3; j++)
        {
            int in;
            cin >> in;
            arr.push_back(in);
        }
        arrays.push_back(arr);
    }
    cout << SmallestRange(arrays, k, 3) << endl;
    return 0;
}
