class Solution {
public: 
    void addSolution(vector<vector<string>>& board,vector<vector<string>>& ans, int n) {
        vector<string> temp;
        for(int i=0; i<n;i++){
            string s = "";
            for(int j=0;j<n;j++){
                //temp.push_back(board[i][j]);
                s += board[i][j];
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }
    bool isSafe(int x, int y, vector<vector<string>>& board, int n){
        
        int row = x;
        int col = y;
        
        // check for same row (row, col--)
        while(col >= 0 ){
            if(board[row][col] == "Q"){
                return false;
            }
            col--;
        }
        
        row = x;
        col = y;
        //check for the diagonal
        // In both reducing condition i.e in above section of the row |
        while(row >=0 && col >= 0){
            if(board[row][col] == "Q"){
                return false;
            }
            row--;
            col--;
        }
        row = x;
        col = y;
        // now in below level
        while(row < n && col >= 0){
            if(board[row][col] == "Q"){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>>& board,vector<vector<string>>& ans, int n) {
        
        //base condition
        if(col == n){
            addSolution(board, ans, n);
            return;
        }
        // 1 case solve karni hain 
        for(int i=0;i<n;i++){
            if(isSafe(i,col, board, n)){
                board[i][col] = "Q";
                solve(col+1, board, ans, n);
                //backtracking
                board[i][col] = ".";
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n,"."));
        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
        
    }
};