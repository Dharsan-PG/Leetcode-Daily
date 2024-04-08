class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i : students) q.push(i);
        
        stack<int> st;
        int round = 0, square = 0;
        for(int i = sandwiches.size()-1; i>=0; i--) {
            st.push(sandwiches[i]);
            if(sandwiches[i] == 0) round++;
            else square++;
        }
        int l = 0;
        while(!q.empty() && l < q.size()) {
            int sw = st.top();
            int stud = q.front();

            if(stud == sw) q.pop(), st.pop(), l = 0;
            else q.pop(), q.push(stud), l++;
        }
        return q.size();
    }
};