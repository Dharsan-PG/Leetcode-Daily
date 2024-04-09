class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,bool>> q;
        for(int i = 0; i<tickets.size(); i++) {
            if(i == k) q.push({tickets[i], 1});
            else q.push({tickets[i], 0});
        }
        int time = 0;
        while(!q.empty()) {
            auto x = q.front();
            x.first--;
            time++;
            if(x.first == 0 && x.second == 1) return time;
            else if(x.first == 0 && x.second == 0) {
                q.pop();
                continue;
            }
            q.pop();
            q.push({x.first , x.second});
        }
        return time;
    }
};