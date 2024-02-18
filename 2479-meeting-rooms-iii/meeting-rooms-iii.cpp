class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> time(n, 0);
        vector<int> ans(n, 0);
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++) {
            int st = meetings[i][0], end = meetings[i][1];
            bool flag = false;
            long long val = 1e18;
            int ptr = -1;
            for (int j = 0; j < n; j++) {
                if (time[j] < val) {
                    val = time[j];
                    ptr = j;
                }
                if (time[j] <= st) {
                    flag = true;
                    ans[j]++;
                    time[j] = end;
                    break;
                }
            }
            if (!flag) {
                ans[ptr]++;
                time[ptr] += ((long long)1 * (end - st));
            }
        }

        int maxi = -1, id = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] > maxi) {
                maxi = ans[i];
                id = i;
            }
        }
        return id;
    }
};