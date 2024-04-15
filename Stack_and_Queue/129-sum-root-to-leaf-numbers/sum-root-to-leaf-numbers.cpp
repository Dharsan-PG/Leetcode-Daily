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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return root->val;
        solve(root, 0);
        return res;
    }

    void solve(TreeNode* node, int s) {
        if(node == NULL) return ;
        s=node->val+10*s;
        if (!node->left && !node->right)
            res += s; 
        solve(node->left, s);
        solve(node->right, s);
    }
};