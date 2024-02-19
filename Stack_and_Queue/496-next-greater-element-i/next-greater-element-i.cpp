class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i = 0; i<nums1.size(); i++) {
            bool flag = 0, t1 = 0;
            for(int j = 0; j<nums2.size(); j++) {
                if(nums1[i] == nums2[j] && flag == 0) { flag = 1; continue; }
                if(nums2[j] > nums1[i] && flag == 1) {
                    res.push_back(nums2[j]);
                    t1 = 1;
                    break;
                }
            }
            if(!t1) {
                res.push_back(-1);
            }
        }
        return res;
    }
};