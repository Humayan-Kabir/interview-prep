class Solution {
public:
    int maxArea(vector<int>& height) {
        int mostWater = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            mostWater = max(mostWater, min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return mostWater;       
    }
};
