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
    int preorderIdx;
    unordered_map<int,int> hashMap;
    TreeNode* getTree(vector<int> &preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int nodeVal = preorder[preorderIdx++];
        TreeNode* currentRoot = new TreeNode(nodeVal);
        currentRoot->left = getTree(preorder, left, hashMap[nodeVal] - 1);
        currentRoot->right = getTree(preorder, hashMap[nodeVal] + 1, right);
        return currentRoot;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIdx = 0;
        hashMap.clear();
        for(int i = 0; i < preorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }
        return getTree(preorder, 0, preorder.size() - 1);
    }
};