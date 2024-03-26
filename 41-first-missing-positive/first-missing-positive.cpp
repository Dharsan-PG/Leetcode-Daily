class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;
        for(auto i : nums) {
            if(i > 0) {
                mp[i]++;
            }
        }

        int res = 1;
        for(auto i : mp) {
            if(i.first != res) return res;
            res++;
        }
        return res;
    }
};