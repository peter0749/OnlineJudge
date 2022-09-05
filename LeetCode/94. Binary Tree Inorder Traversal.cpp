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
    // To iterate is human,
    void iterative(TreeNode* root, vector<int> &ret) {
        if (root == NULL) return;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode *node = root->left;
        while(true) {
            if (node == NULL) {
                if (stk.empty()) break;
                node = stk.top(); stk.pop();
                ret.push_back(node->val);
                node = node->right;
                continue;
            }
            stk.push(node);
            node = node->left;
        }
    }
    
    // to recurse, divine.
    void dfs(TreeNode* root, vector<int> &ret) {
        if (root==NULL) return;
        dfs(root->left, ret);
        ret.push_back(root->val);
        dfs(root->right, ret);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> solution;
        // I'm a human.
        iterative(root, solution);
        return solution;
    }
};
