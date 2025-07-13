class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
           unordered_set<string> s;
           for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                string row = string(1, board[i][j]) + "_ROW" + to_string(i);
                string col = string(1, board[i][j]) + "_COL" + to_string(j);
                string box = string(1, board[i][j]) + "_ROW" + to_string(i/3)+string(1, board[i][j]) + "_COL" + to_string(j/3);
                if(board[i][j]=='.') continue;
                if(s.find(row) !=s.end() ||s.find(col) !=s.end() || s.find(box) !=s.end()) return false;
                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
           } 
           return true;
        }
    };