/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        solve(root, inorder);

        int st = 0;
        int end = inorder.size() - 1;
        while (st < end) {
            int sum = inorder[st] + inorder[end];
            if (sum == k)
                return true;
            else if (sum > k)
                end--;
            else
                st++;
        }

        return false;
    }

    void solve(TreeNode* root, vector<int>& res) {
        if (root == NULL)
            return;
        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
    }
};