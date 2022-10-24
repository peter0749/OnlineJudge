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
    void traverse(TreeNode* root, int &prev, bool &valid, bool &first) {
        if (root == NULL) return;
        traverse(root->left, prev, valid, first);
        int val = root->val;
        if (!first && prev >= val) {
            valid = false;
            return;
        }
        first = false;
        prev = val;
        traverse(root->right, prev, valid, first);
    }
    bool isValidBST(TreeNode* root) {
        int prev=INT_MIN;
        bool valid=true;
        bool first=true;
        traverse(root, prev, valid, first);
        return valid;
    }
};
