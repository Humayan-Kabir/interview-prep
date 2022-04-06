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
    TreeNode* lastVisitedElement;
    TreeNode* findLinkedList(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        lastVisitedElement = root;
        TreeNode* leftLinkedList = findLinkedList(root->left);
        TreeNode* rightMostELementFromLeft = lastVisitedElement;
        TreeNode* rightLinkedList = findLinkedList(root->right);
        if (leftLinkedList == nullptr) {
            root->right = rightLinkedList;
        } else {
            root->right = leftLinkedList;
            rightMostELementFromLeft->right = rightLinkedList;
        }
        root->left = nullptr;
        return root;
    }
    void flatten(TreeNode* root) {
        findLinkedList(root);             
    }
};
