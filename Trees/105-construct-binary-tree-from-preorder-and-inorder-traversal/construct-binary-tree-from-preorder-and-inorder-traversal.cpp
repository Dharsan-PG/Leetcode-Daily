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
    map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int P_St, int P_End,
                    vector<int>& inorder, int I_St, int I_End) {

        if (P_St > P_End || I_St > I_End)
            return NULL;

        TreeNode* root = new TreeNode(preorder[P_St]);

        int pos = mp[root->val];
        int left = pos - I_St;

        root->left =
            build(preorder, P_St + 1, P_St + left, inorder, I_St, pos - 1);
        root->right =
            build(preorder, P_St + 1 + left, P_End, inorder, pos + 1, I_End);

        return root;
    }
};