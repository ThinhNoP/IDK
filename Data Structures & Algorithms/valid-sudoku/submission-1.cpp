class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 for
        // hash set

        // bitmask
        int N = 9;
        vector<vector<int>> check(3, vector(N, 0));
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == '.') continue;
                int k = (i/3)*3 + (j/3);

                int val = board[i][j] - '1';
                if( (check[0][i] & (1 << val)) || 
                    (check[1][j] & (1 << val)) || 
                    (check[2][k] & (1 << val)))
                        return false;

                check[0][i] |= (1 << val);
                check[1][j] |= (1 << val);
                check[2][k] |= (1 << val);
            }
        }

        return true;
    }
};
