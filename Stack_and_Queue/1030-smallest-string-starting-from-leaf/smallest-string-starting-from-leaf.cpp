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
    string res ="}";  //ascii 125
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return res;
    }

    void solve(TreeNode* node, string s) {
        if(node == NULL) return;

        s = string(1, node->val+'a')+s;
        if(node->left == NULL && node->right == NULL) res = min(s, res);
        solve(node->left, s);
        solve(node->right, s);

    }
};