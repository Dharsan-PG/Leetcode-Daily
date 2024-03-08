class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums) {
            mp[i]++;
        }
        int maxf = INT_MIN;
        for(auto& i : mp) {
            if(maxf < i.second) {
                maxf = i.second;
            } 
        }

        int maxi = 0;
        for(auto& i : mp) {
            if(i.second == maxf) {
                maxi += maxf;
            }
        }

        return maxi;
    }
};