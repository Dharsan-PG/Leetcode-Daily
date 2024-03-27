class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int l = 0, r = 0, prod = 1, cnt = 0;
        int n = nums.size();
        while(r < n) {
            prod *= nums[r++];
            while(l< r && prod >= k) {
                prod /= nums[l++];
            }
            cnt += (r - l);
        }
        return cnt;
    }
};