#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& maze, int n, vector<vector<bool>>& visited_arr) {
    cout<<"maze is"<<endl;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"visisted array is"<<endl;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited_arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int newx, int newy, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited_arr) {

    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited_arr[newx][newy] != 1 && maze[newx][newy] == 1){
        return true;
    }
    else{
        return false;
    }
}

void ratInAMaze(vector<vector<int>>& maze, int n, vector<vector<bool>>& visited_arr,
int x, int y, string path , vector<string>& ans ) {

    //print(maze, n, visited_arr);
    if(x == n-1 && y == n-1){

        ans.push_back(path);
        return ;
    }
    //cout<<"value present before visited arryy is"<<visited_arr[x][y]<<endl;
    visited_arr[x][y] = 1;
    //cout<<"value present at visited arryy is"<<visited_arr[x][y]<<endl;
    //down
    if(isSafe(x+1, y, n, maze, visited_arr)){
        path += "D";
        ratInAMaze(maze,n,visited_arr,x+1,y,path,ans);
    }
    //left
    if(isSafe(x, y-1, n, maze, visited_arr)){
        path += "L";
        ratInAMaze(maze,n,visited_arr,x,y-1,path,ans);
    }
    //right
    if(isSafe(x, y+1, n, maze, visited_arr)){
        path += "R";
        ratInAMaze(maze,n,visited_arr,x,y+1,path,ans);
    }
    //top
    if(isSafe(x-1, y, n, maze, visited_arr)){
        path += "U";
        ratInAMaze(maze,n,visited_arr,x-1,y,path,ans);
    }
    visited_arr[x][y] = 0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n);
    vector<string> ans;
    for(int i=0;i<n;i++){
        maze[i] = vector<int>(n);
        for(int j=0;j<n;j++){
            int l;
            cin>>l;
            maze[i][j] = l;
        }
    }
    string path = "";
    vector<vector<bool>> visited_arr(n,vector<bool>(n,0));
    ratInAMaze(maze, n, visited_arr, 0, 0, path, ans);
    cout<<"The ans string is"<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
