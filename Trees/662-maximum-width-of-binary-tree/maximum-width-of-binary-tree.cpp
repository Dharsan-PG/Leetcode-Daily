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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        long long ans = INT_MIN;
        q.push({root, 0});
        while(!q.empty()) {
            int sz = q.size();
            int lvlmin = q.front().second;
            long long f,l;
            for(int i = 0; i< sz; i++) {
                TreeNode* node = q.front().first;
                int curr = q.front().second;
                curr -= lvlmin;
                q.pop();
                if(i == 0) f = curr;
                if(i == sz-1) l = curr;
                if(node->left) q.push({node->left, (long long)curr*2+1});
                if(node->right) q.push({node->right, (long long)curr*2+2});
            }
            ans = max(ans, l-f+1);
        }
        return ans;
    }
};