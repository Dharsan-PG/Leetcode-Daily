class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return solve(nums, 0, 0);
        // if(res>nums[n-1]) return res;
        // return -1; 
    }

    long long solve(vector<int>& nums,int i,long long sum) {
        if(i==nums.size()) return -1;
        sum+=nums[i];
        long long res =-1;
        if(sum-nums[i]>nums[i]) {res = sum;cout<<res<<endl;}
        return max(res,solve(nums,i+1,sum));
    }
};