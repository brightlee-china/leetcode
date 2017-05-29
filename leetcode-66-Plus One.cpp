class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int in = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            int cur = digits[i] + in;
            digits[i] = cur % 10;
            in = cur / 10;
        }
        
        if (in == 1)
            digits.insert(digits.begin(), in);
        
        return digits;
    }
};