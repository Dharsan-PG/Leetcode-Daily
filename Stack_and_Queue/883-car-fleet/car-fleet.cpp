class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> car;
        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }

        sort(car.begin(), car.end());
         stack<float> st;
        for(int i=0; i<car.size(); i++){
            float time = (target-car[i].first) / (float)car[i].second;
            if(st.empty()){
                st.push(time);
            }
            else{
                while(!st.empty() && time >= st.top()){
                    st.pop();
                }

                st.push(time);
            }
        }

        return st.size();
    }
};