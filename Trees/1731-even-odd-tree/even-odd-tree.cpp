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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool lvl = 0;
        while (!q.empty()) {
            int sz = q.size();
            int prev = -1;
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                if (!lvl && (node->val % 2 == 0 || prev != -1 && node->val <= prev)) // even
                    return false;
                else if (lvl && (node->val % 2 == 1 || prev != -1 && node->val >= prev))
                    return false;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                prev = node->val;
            }
            lvl = !lvl;
        }
        return true;
    }
};