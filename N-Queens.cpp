class Solution {
public:
    bool safe(int r, int c, vector<string>& board, int n){
        int x = r;
        int y = c;

        // Check left in col
        while(y>=0){
            if(board[x][y--] == 'Q') return 0;
        }

        x = r, y = c;
        //Check upper left diago
        while(x>=0 && y>=0){
            if(board[x--][y--] == 'Q') return 0;
        }

        x = r, y = c;
        //Check lower left diago
        while(x<n && y>=0){
            if(board[x++][y--] == 'Q') return 0;
        }

        return 1;
    }

    void solve(int c, vector<vector<string>>& ans, vector<string>& board, int n){
        if(c == n){
            ans.push_back(board);
            return ;
        }

        for(int r=0; r<n; r++){
            if(safe(r, c, board, n)){
                board[r][c] = 'Q';
                solve(c+1, ans, board, n);
                board[r][c] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0, ans, board, n);
        return ans;
    }
};
