class Solution {
    public:
        int f(vector<int>& wt, int cap){
            int d = 1, sum = 0, j = 0, n = wt.size();
            while(j < n){
                if(sum + wt[j] <= cap) sum += wt[j];
                else{
                    d++;
                    sum = wt[j];
                }
                j++;
            }
            return d;
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int total_sum = 0, min_cap = INT_MIN, ans = 0;
            for(auto wt : weights){
                total_sum+= wt;
                min_cap = max(min_cap, wt);
            }
            int mid = min_cap + (total_sum - min_cap)/2;
            int n = weights.size();
            while(min_cap <= total_sum){
                int mid = min_cap + (total_sum - min_cap)/2;
                int actual_day = f(weights, mid);
                if(actual_day <= days){
                    ans = mid;
                    total_sum = mid - 1;
                }else{
                    min_cap = mid + 1;
                }
            }
            return ans;
        }
    };