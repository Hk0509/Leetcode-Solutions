class Solution {
public:
    bool safe(int r, int c, vector<vector<char>>& board, char val){
        for(int i=0; i<board.size(); i++){
            if(board[r][i] == val) return 0;
            if(board[i][c] == val) return 0;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3] == val) return 0;
        }
        return 1;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(board[r][c] == '.'){
                    for(char val= '1'; val<= '9'; val++){
                        if(safe(r, c, board, val)){
                            board[r][c] = val;
                            if(solve(board))
                                return 1;
                            else
                                board[r][c] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return ;
    }
};
