class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stk;
        heights.push_back(0);
        int result = 0;
        for (int i = 0; i < heights.size(); i ++) {
            while (stk.size() > 0 && heights[stk.back()] >= heights[i]) {
                int h = heights[stk.back()];
                stk.pop_back();
                
                int a = stk.size() > 0 ? stk.back() : -1; // if stk is empty, than we know every front height maxer than the current one 
                if (h * (i - a - 1) > result)  
                    result = h * (i - a - 1);
            }
            
            stk.push_back(i);
        }
        
        return result;
    }
};