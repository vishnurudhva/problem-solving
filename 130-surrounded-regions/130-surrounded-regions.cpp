class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++)
            if(board[i][0] == 'O')
                dfs(board, i, 0, r, c);
        
        for(int i = 0; i < r; i++)
            if(board[i][c - 1] == 'O')
                dfs(board, i, c - 1, r, c);
        
        for(int i = 0; i < c; i++)
            if(board[0][i] == 'O')
                dfs(board, 0, i, r, c);
        
        for(int i = 0; i < c; i++)
            if(board[r - 1][i] == 'O')
                dfs(board, r - 1, i, r, c);
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == 'I')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int r, int c) {
        if(i == -1 || j == -1 || i == r || j == c || board[i][j] == 'X' || board[i][j] == 'I') return;
        board[i][j] = 'I';
        dfs(board, i + 1, j, r, c);
        dfs(board, i - 1, j, r, c);
        dfs(board, i, j + 1, r, c);
        dfs(board, i, j - 1, r, c);
    }
};