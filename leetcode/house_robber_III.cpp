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

	pair<int,int> rec(TreeNode *root) {
		if (!root) return {0, 0};
		auto leftResult = rec(root->left);
		auto rightResult = rec(root->right);
		return {root->val + leftResult.second + rightResult.second, max(leftResult.first, leftResult.second) + max(rightResult.first, rightResult.second)};
	}
	int rob(TreeNode* root) {
		int black = 0, white = 0;
		auto result = rec(root);
		return max(result.first, result.second);
	}
};

