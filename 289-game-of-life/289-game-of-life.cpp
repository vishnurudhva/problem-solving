class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
            {
                int neighborSum = getNeighborSum(board, i, j);
                if(board[i][j] == 1 && (neighborSum < 2 || neighborSum > 3))
                    board[i][j] = -1;
                else if(board[i][j] == 0 && neighborSum == 3)
                    board[i][j] = 2;
            }
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == -1) board[i][j] = 0;
    }
    
    int getNeighborSum(vector<vector<int>>& board, int i, int j)
    {
        int result = 0;
        int x[] = {0, -1, 1};
        int y[] = {0, 1, -1};
        for(int r = 0; r < 3; r++)
            for(int c = 0; c < 3; c++)
                if((x[r] == 0 && y[c] == 0) || i + x[r] >= board.size() || i + x[r] < 0 
                    || j + y[c] >= board[0].size() || j + y[c] < 0 || board[i + x[r]][j + y[c]] == 2)
                    continue;
                else
                    result += abs(board[i + x[r]][j + y[c]]);

        return result;
    }
};