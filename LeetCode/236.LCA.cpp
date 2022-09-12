/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// This solution doesn't use the BST assumption. Just searches LCA in Binary Tree directly.
class Solution {
public:
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **LCA, int &min_depth, int lev) {
        if (root==NULL) return INT_MAX;
        int this_depth = (root == p || root == q) ? lev : INT_MAX;
        int left_depth = dfs(root->left, p, q, LCA, min_depth, lev+1);
        int right_depth = dfs(root->right, p, q, LCA, min_depth, lev+1);
        if (this_depth != INT_MAX) {
            if (min(left_depth, right_depth) - this_depth < min_depth) {
                min_depth = min(left_depth, right_depth) - this_depth;
                *LCA = root;
            }
        }
        if (left_depth != INT_MAX && right_depth != INT_MAX) {
            if (max(left_depth, right_depth) - lev < min_depth) {
                min_depth = max(left_depth, right_depth) - lev;
                *LCA = root;
            }
        }
        return min(min(left_depth, right_depth), this_depth);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode **LCA = &root;
        int min_depth = INT_MAX;
        dfs(root, p, q, LCA, min_depth, 0);
        return *LCA;
    }
};
