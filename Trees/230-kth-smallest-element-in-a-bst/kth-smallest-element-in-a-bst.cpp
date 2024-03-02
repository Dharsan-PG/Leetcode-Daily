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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return ans;
        int i =0;
        solve(root, k, i);
        return ans;
    }

    void solve(TreeNode* root, int k,int& i) {
        if(root == NULL) return ;
        solve(root->left,k,i);
        i+=1;
        if(k == i) {ans = root->val; return;}
        solve(root->right,k, i);
    }
};