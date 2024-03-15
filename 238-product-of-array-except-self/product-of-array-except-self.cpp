class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        int prod = 1;
        for(int& i : nums) {
            pre.push_back({prod});
            prod *= i;
        }
        prod = 1;
        for(int i = nums.size()-1; i>=0; i--) {
           pre[i]*=prod;
           prod*=nums[i]; 
        }  
        
        return pre;
    }
};