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
public:
    map<int,int> hashMap;
    int whereInPreOrder = 0;
    TreeNode* rec(vector<int> &preorder, vector<int>& inorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int element = preorder[whereInPreOrder++];
        TreeNode *node = new TreeNode(element);
        node->left = rec(preorder, inorder, left, hashMap[element] - 1);
        node->right = rec(preorder, inorder, hashMap[element] + 1, right);
        return node; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }
        return rec(preorder, inorder, 0, inorder.size() - 1);
    }
};
