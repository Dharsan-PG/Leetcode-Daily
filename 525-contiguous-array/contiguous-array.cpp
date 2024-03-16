class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int s = 0;
        int res = 0;
        for(int i = 0; i<n; i++) {
            s += nums[i] == 0 ? -1 : 1;
            if(s == 0){
                res = i+1;
            }
            else if(mp.find(s) != mp.end()) {
                res = max(res, i-mp[s]);
            }
            else {
                mp[s] = i;
            }
        }
        // for(auto [k, v] : mp) {
        //     cout<< k<<" : "<<v<<endl;
        // }
        return res;
    }
};