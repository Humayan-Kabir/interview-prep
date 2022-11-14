/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string getSerializedString(TreeNode *root) {
        if (root == nullptr) {
            return "#";
        }
        string serialized = "!";
        serialized += to_string(root->val);
        serialized += getSerializedString(root->left);
        serialized += getSerializedString(root->right);
        return serialized;
    }
    vector<int> prefix_function(string &s) {
        int n = (int) s.length();
        vector<int> pi(n);
        for(int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }
    bool isMatched(string &text, string &pattern) {
        //calculate lps
        vector<int> prefix = prefix_function(text);
        //match string
        int i = 0;
        int j = 0;
        while(i < text.length() && j < pattern.length()) {
            if (text[i] == patter[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return j == (int)pattern.length();
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string text = getSerializedString(root);
        string pattern = getSerializedString(subRoot);
        return isMatched(text, pattern);      
    }
};