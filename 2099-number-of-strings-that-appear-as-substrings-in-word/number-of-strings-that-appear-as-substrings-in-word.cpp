class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto& i : patterns) {
            if(word.find(i) != string::npos) cnt++;  // string::npos or -1
        }
        return cnt;
    }
};