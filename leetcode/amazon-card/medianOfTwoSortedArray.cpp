class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) {
        	return findMedianSortedArrays(nums2, nums1);
        }
        int half = (len1 + len2) / 2;
        int low = 0, high = len1;
        while(low <= high) {
        	int mid = (low + high) / 2;
        	int rem = half - mid;
        	int a1 = mid == 0 ? INT_MIN : nums1[mid-1];
        	int a2 = mid == len1 ? INT_MAX : nums1[mid];
        	int b1 = rem == 0 ? INT_MIN : nums2[rem-1];
        	int b2 = rem == len2 ? INT_MAX : nums2[rem];
        	if (a1 <= b2 && b1 <= a2) {
        		if ((len1 + len2) % 2 == 0) {
        			return (max(a1, b1) + min(a2, b2)) / 2.0;		
        		} else {
        			return 1.0 * min(a2, b2);
        		}
        	} else if (a1 > b2) {
        		high = mid - 1;
        	} else {
        		low = mid + 1;
        	}
        }
        return 0;
    }
};
