
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