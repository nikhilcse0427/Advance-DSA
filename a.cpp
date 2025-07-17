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
                class Solution {
                    public:
                        bool isValid(string s){
                            stack<char> stk;
                            for(int i=0;i<s.size();i++){
                                if(s[i]=='(') stk.push(s[i]);
                                else{
                                    if(stk.empty()) return false;
                                    else stk.pop();
                                }
                            }
                            return stk.empty();
                        }
                    
                        void solve(string curr,int n,vector<string> &ans){
                                if(curr.length()==2*n){
                                    if(isValid(curr)){
                                        ans.push_back(curr);
                                    }
                                    return;
                                }
                                curr.push_back('(');
                                solve(curr, n, ans);
                                curr.pop_back();
                                curr.push_back(')');
                                solve(curr, n, ans);
                                curr.pop_back();
                            }
                        vector<string> generateParenthesis(int n) {
                            vector<string> ans;
                            string curr = "";
                            solve(curr, n, ans);
                            return ans;
                        }
                    };
           } 
           return true;
        }
    };