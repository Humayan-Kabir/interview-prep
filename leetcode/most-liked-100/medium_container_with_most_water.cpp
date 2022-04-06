class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, left = 0, right = height.size() - 1;
        while(left < right) {
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;       
    }
};
