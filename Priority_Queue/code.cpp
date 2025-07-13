class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char, int> map;
            for (char task : tasks) {
                map[task]++;
            }
    
            priority_queue<pair<int, char>> pq;
            for (auto el : map) {
                pq.push({el.second, el.first});
            }
    
            int ans = 0;
    
            while (!pq.empty()) {
                int cycle = n + 1;
                vector<pair<int, char>> temp;
    
                while (cycle && !pq.empty()) {
                    auto [count, ch] = pq.top();
                    pq.pop();
                    if (count - 1 > 0) {
                        temp.push_back({count - 1, ch});
                    }
                    ans++;
                    cycle--;
                }
    
                for (auto el : temp) {
                    pq.push(el);
                }
    
                if (!pq.empty()) {
                    ans += cycle;
                }
            }
    
            return ans;
        }
    };