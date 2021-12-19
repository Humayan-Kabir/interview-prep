class Solution {
public:
    bool canJump(vector<int>& nums) {
       int farthestDist = 0, currentMoveEnd = 0;
       for(int i = 0; i < nums.size(); i++) {
            farthestDist = max(farthestDist, i + nums[i]);
            if (i == currentMoveEnd) {
                currentMoveEnd = farthest;
            }
            if (i > currentMoveEnd) return false;
       }
      return true; 
    }
};
