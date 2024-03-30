class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }

    int solve(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), res = 0;
        map<int, int> mp;

        while(r < n) {
            mp[nums[r]]++;
            while(mp.size() > k && l <= r) {    
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
};