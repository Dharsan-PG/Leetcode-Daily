class Solution {
public:
    string removeDigit(string number, char digit) {
        string result = "";
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                string temp =
                    number.substr(0, i) + number.substr(i + 1, number.size());
                result = max(temp, result);
            }
        }
        return result;
    }
};