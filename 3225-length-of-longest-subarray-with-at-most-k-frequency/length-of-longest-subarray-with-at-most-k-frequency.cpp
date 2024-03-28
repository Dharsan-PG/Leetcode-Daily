class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0, maxi = INT_MIN;
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0 ; i < n; i++) {
            mp[nums[r]]++;
            while(mp[nums[i]] > k) {
                mp[nums[l++]]--;
            }
            cnt = (r-l+1);
            maxi = max(maxi, cnt);
            r++;
        }
        return maxi;
    }
};