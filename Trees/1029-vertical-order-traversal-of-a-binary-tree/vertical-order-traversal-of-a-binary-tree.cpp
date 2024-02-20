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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> res;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        res[0].push_back(root->val);
        while (!q.empty()) {
            int sz = q.size();
            map<int, multiset<int>> m;
            while (sz--) {
                int n = q.front().first;
                TreeNode* node = q.front().second;
                q.pop();
                if (node->left != NULL) {
                    q.push({n - 1, node->left});
                    m[n - 1].insert(node->left->val);
                }
                if (node->right != NULL) {
                    q.push({n + 1, node->right});
                    m[n + 1].insert(node->right->val);
                }
            }
            for (auto i : m) {
                for (auto j : i.second) {
                    res[i.first].push_back(j);
                }
            }
        }
        vector<vector<int>> ans;
        for (auto i : res) {
            ans.push_back({i.second.begin(), i.second.end()});
        }

        return ans;
    }
};