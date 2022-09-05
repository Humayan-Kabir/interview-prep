class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        int px = m - 1;
        int py = n - 1;
        while(px >= 0 && py >= 0) {
            nums1[pos--] = (nums1[px] >= nums2[py]) ? nums1[px--] : nums2[py--];
        }
        while(py >= 0) nums1[pos--] = nums2[py--];        
    }
};
