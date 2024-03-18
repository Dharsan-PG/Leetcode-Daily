class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char ,int> mp;
        int n = words.size();
        for(auto i : words) {
            for (auto j : i) {
                mp[j]++;
            }
        }
        for(auto i : mp){
            if(i.second%n) return false;
        }
        return true;
    }
};