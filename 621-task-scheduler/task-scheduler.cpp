class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        unordered_map<char,int> mp;
        for(auto i : tasks) {
            mp[i]++;
        }
        int cnt = 0;
        priority_queue<int> pq;
        for(auto i : mp) pq.push(i.second);

        while(!pq.empty()) {
            vector<int> temp;
            int t = 0;
            for(int i = 0; i<n+1; i++) {
                if(!pq.empty()) {
                    int cyc = pq.top()-1;
                    if(cyc) temp.push_back(cyc);
                    pq.pop();
                    t++;
                }
            }
            for(int j : temp) {
                pq.push(j);
            }
            cnt += (pq.empty()? t : n+1);
        }
        return cnt;
    }
};