class Solution {
public:
    vector<int> vt;
    int maxSubArray(vector<int>& nums) {
        vt = nums;
        return findBestSubArray(0, nums.size() - 1);
    }
    int findBestSubArray(int left, int right) {
        if (left > right) return INT_MIN;
        int mid = (left + right) / 2;
        int leftResult = findBestSubArray(left, mid - 1);
        int rightResult = findBestSubArray(mid + 1, right);
        int bestLeftSum = 0;
        int bestRightSum = 0;
        int sum = 0;
        for(int i = mid - 1; i >= left; i--) {
            sum += vt[i];
            bestLeftSum = max(bestLeftSum, sum); 
        }
        sum = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += vt[i];
            bestRightSum = max(bestRightSum, sum);
        }
        int bestCombination = bestLeftSum + vt[mid] + bestRightSum;
        return max(max(leftResult, rightResult), bestCombination);
    }
};
