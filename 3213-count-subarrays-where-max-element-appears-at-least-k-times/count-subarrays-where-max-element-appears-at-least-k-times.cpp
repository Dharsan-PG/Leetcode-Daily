class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int l = 0,  r = 0 , cnt = 0, n = nums.size(), maxi = INT_MIN;
        maxi = *max_element(nums.begin(),nums.end());
        while(r < n) {
            if(maxi == nums[r]) cnt++;
            while(cnt >= k) {
                if(nums[l] == maxi) cnt--;
                l++;    
            }
            res += l;
            r++;
        } 
        return res;
    }
};