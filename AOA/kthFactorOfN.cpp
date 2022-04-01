class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        int root = sqrt(n);
        for(int i = 1; i < root + 1; i++) {
            if (n % i == 0) {
                k--;
                factors.push_back(i);
                if (k == 0) {
                    return i;
                }
            }
        }
        if (root * root == n) {
            k++;
        }       
        return factors.size() >= k ? n / factors[factors.size() - k] : -1;
    }
};
