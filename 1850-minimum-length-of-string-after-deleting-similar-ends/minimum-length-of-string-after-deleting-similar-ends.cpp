class Solution {
public:
    int minimumLength(string s) {
        int p = 0;
        int q = s.size()-1;
        while(p<q && s[p] == s[q]) {
            char c = s[p];
            while(p<=q && s[p] == c) p++;
            while(p<=q && s[q] == c) q--;
        }
        return q-p+1;
    }
};