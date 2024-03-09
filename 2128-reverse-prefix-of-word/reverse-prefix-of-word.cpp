class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        string res = word;
        for(i = 0; i< word.size(); i++) {
            if(word[i] == ch) {
                reverse(res.begin(), res.begin()+i+1);
                break;
            }
        }
        return res;
    }
};