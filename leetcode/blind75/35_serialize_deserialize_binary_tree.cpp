/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if (root == nullptr) {
            return "N,";
       }
       string str = to_string(root->val);
       str += ",";
       str += serialize(root->left);
       str += serialize(root->right);
       return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        queue<string> treeNodes;
        string node;
        while(std::getline(ss, node, ',')) {
            treeNodes.push(node);
        }
        return getTree(treeNodes);
    }

    TreeNode* getTree(queue<string> &nodes) {
        string node = nodes.front();
        nodes.pop();
        if (node == "N") {
            return nullptr;
        }
        TreeNode *current = new TreeNode(stoi(node));
        current->left = getTree(nodes);
        current->right = getTree(nodes);
        return current;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));