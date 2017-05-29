class Solution {
public:
    int trap(vector<int>& height) {
       int result = 0;
       int leftmax = 0, rightmax = 0;
       int left = 0, right = height.size() - 1;
       while (left < right) {
           if (height[left] <= height[right]) {
               if (leftmax <= height[left])
                    leftmax = height[left];
                else 
                    result += leftmax - height[left];
                
                left ++;
           }
           else {
               if (rightmax <= height[right])
                    rightmax = height[right];
                else 
                    result += rightmax - height[right];
                
                right --;
           }
       }
       
       return result;
    }
};