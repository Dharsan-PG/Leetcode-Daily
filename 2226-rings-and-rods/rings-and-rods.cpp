class Solution {
public:
    int countPoints(string rings) {
        vector<set<int>> v(10);
        for (int i = 0; i < rings.size(); i += 2)
            v[rings[i + 1] - '0'].insert(rings[i]);

        int ans = 0;
        for (int i = 0; i < 10; ++i){
            if (v[i].size() == 3)
                ans++;
        }
        return ans;
    }
};