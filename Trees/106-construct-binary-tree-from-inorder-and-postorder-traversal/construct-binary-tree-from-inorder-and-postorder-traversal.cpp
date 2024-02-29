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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = build(postorder, 0, postorder.size() - 1, inorder, 0,
                               inorder.size() - 1);
        return root;
    }
    TreeNode* build(vector<int>& postorder, int P_St, int P_End,
                    vector<int>& inorder, int I_St, int I_End) {

        if (P_St > P_End || I_St > I_End)
            return NULL;

        TreeNode* root = new TreeNode(postorder[P_End]);

        int pos = mp[root->val];
        int left = pos - I_St;

        root->left =
            build(postorder, P_St, P_St + left - 1, inorder, I_St, pos - 1);
        root->right =
            build(postorder, P_St + left, P_End - 1, inorder, pos + 1, I_End);

        return root;
    }
};