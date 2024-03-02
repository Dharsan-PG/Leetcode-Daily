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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        TreeNode* node = root;
        if(root->val == key) return solve(root);
        while(root != nullptr) {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) root->left = solve(root->left); 
                else root = root->left;
            }
            else {
                if(root->right != NULL && root->right->val == key) root->right = solve(root->right); 
                else root = root->right;
            }
        }
        return node;
    }

    TreeNode* solve(TreeNode* root) {
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* child = root->right;
        TreeNode* last = find(root->left);
        last->right = child;
        return root->left;
    }

    TreeNode* find(TreeNode* root) {
        if(root->right == NULL) return root;
        return find(root->right);
    }
};