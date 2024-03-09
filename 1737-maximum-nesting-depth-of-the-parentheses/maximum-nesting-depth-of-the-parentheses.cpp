class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt = 0;
        for(auto& i : s) {
            if(i == '(') {
                st.push(i);
            }
            else if(i == ')') {
                int sz = st.size();
                cnt = max(cnt,sz);
                st.pop();
            }
        }
        return cnt;
    }
};