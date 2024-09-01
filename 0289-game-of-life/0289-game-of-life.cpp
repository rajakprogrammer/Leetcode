class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Directions array representing the 8 possible neighbors
        vector<int> directions = {-1, 0, 1};
        
        // Iterate through each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                // Check all 8 neighbors
                for (int x : directions) {
                    for (int y : directions) {
                        if (!(x == 0 && y == 0)) {
                            int r = i + x;
                            int c = j + y;
                            
                            // Check if the neighbor is within bounds and is currently live
                            if (r >= 0 && r < m && c >= 0 && c < n && abs(board[r][c]) == 1) {
                                liveNeighbors++;
                            }
                        }
                    }
                }
                
                // Apply the rules of the game
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    // Mark as dead in the next state, but keep current state as live (use -1)
                    board[i][j] = -1;
                }
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    // Mark as live in the next state (use 2)
                    board[i][j] = 2;
                }
            }
        }
        
        // Final pass to update the board to the next state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
