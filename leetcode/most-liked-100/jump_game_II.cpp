class Solution {
public:
    int jump(vector<int>& nums) {
        int moveEnd = 0;
        int jump = 0;
        int nextBest = 0;
        for(int i = 0; i < nums.size(); i++) {
            nextBest = max(nextBest, i + nums[i]);
            if (moveEnd == i && i != nums.size() - 1) {
                jump++;
                moveEnd = nextBest;
                //new jump
            }
        }
        return jump;
    }
};
