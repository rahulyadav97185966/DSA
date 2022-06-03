#include <bits/stdc++.h>
using namespace std;
void print(int **arr, int **visited_arr, int n)
{
    cout << "Array is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Visisted Array is: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited_arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void RateinMaze(int **arr, vector<string> &ans, int x, int y, int n, string output, int **visited_arr)
{
    cout << "the output string is: " << output << "\n";
    print(arr, visited_arr, n);
    // base Condition
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(output);
        return;
    }
    // recursive call
    visited_arr[x][y] = 1;
    if (x + 1 < n)
    {
        if (arr[x + 1][y] == 1 && visited_arr[x + 1][y] == 0 )
        {
            output += "D";
            RateinMaze(arr, ans, x + 1, y, n, output, visited_arr);
            output.pop_back();
        }
    }
    if (y - 1 >= 0)
    {
        if (arr[x][y - 1] == 1 && visited_arr[x][y - 1] == 0)
        {
            output += "L";
            RateinMaze(arr, ans, x, y - 1, n, output, visited_arr);
            output.pop_back();
        }
    }

    if ((y + 1) < n)
    {
        if (arr[x][y + 1] == 1 && visited_arr[x][y + 1] == 0)
        {
            output += "R";
            RateinMaze(arr, ans, x, y + 1, n, output, visited_arr);
            output.pop_back();
        }
    }
    if ((x - 1) >= 0)
    {
        if (arr[x - 1][y] == 1 && visited_arr[x - 1][y] == 0)
        {
            output += "U";
            RateinMaze(arr, ans, x - 1, y, n, output, visited_arr);
            output.pop_back();
        }
    }

    visited_arr[x][y] = 0;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **visited_arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited_arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited_arr[i][j] = 0;
        }
    }
    vector<string> ans;
    string ouput = "";
    RateinMaze(arr, ans, 0, 0, n, ouput, visited_arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}