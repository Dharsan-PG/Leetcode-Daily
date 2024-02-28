/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        mapping(root,parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int lvl = 0;
        while(!q.empty()) {
            if(lvl++ == k) break;
            int sz = q.size();
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }

        vector<int> res;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }

    void mapping(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // for(auto i : parent) {
        //     cout<< i.first->val<<' '<<i.second->val<<endl;
        // }
    }
};