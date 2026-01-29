class Solution {
public:
   vector<bool> leftDia,rightDia, col;
   vector<vector<string>> result;
    vector<string> board;

    bool isSafe(int row, int c,int n){
        bool isCol = col[c];
        bool isLD = leftDia[(row - c) + (n - 1)];
        bool isRD = rightDia[row + c];
        if( !isCol && !isLD && !isRD){
            return true;
        }
        return false;
    }

    void solve(int row,int n){
        if( row == n){
            result.push_back(board);
            return;
        }
        for(int c =0; c<n;c++){
            if(isSafe(row,c,n)){
                board[row][c]='Q';
                col[c] = true;
                leftDia[(row - c) + (n - 1)] = true;
                rightDia[row + c] = true;
                solve(row+1, n);
                board[row][c] = '.';
                col[c] = false;
                leftDia[(row - c) + (n - 1)] = false;
                rightDia[row + c] = false;
            }
            
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n,string(n,'.'));
        int dSize = 2*n -1;
        leftDia = vector<bool>(dSize, false);
        rightDia = vector<bool>(dSize, false);
        col = vector<bool>(n, false);
        solve(0,n);
        return result;
    }
};