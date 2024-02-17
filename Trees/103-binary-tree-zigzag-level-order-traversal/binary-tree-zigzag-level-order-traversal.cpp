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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        bool ltr = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> lvl(sz);
            for(int i=0;i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index  = (ltr) ? i : (sz-i-1);
                lvl[index] = node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                // lvl.push_back(node->val);
            }
            ltr = !ltr;
            res.push_back(lvl);
        }
        return res;
    }
};