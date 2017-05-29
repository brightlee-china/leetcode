class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i ++) {
            int other = target - nums[i];
            if (m.find(other) != m.end()) {
                result.push_back(m[other]);
                result.push_back(i);
                return result;
            }
            else {
                m[nums[i]] = i;
            }
        }
    }
};