class Solution {
public:
	map<int, pair<int, int>> mb;
	pair<int, int> dfs(vector<vector<int>>&adj, int node, vector<int>&vis) {
		vis[node] = 1;
		int temp = 0;
		int cnt = 0;
		for (auto &it : adj[node]) {
			if (!vis[it]) {
				pair<int, int> p = dfs(adj, it, vis);
				temp += p.second;
				cnt += p.first;
			}
		}
		mb[node] = {cnt + 1, temp};
		return {cnt + 1, cnt + 1 + temp};
	}
	void dfs2(vector<vector<int>>&adj, vector<int>&vis, int parent, int node, int maxsize) {
		vis[node] = 1;
		mb[node].second += (mb[parent].second + (maxsize - mb[node].first) - (mb[node].first + mb[node].second));
		for (auto &it : adj[node]) {
			if (!vis[it]) {
				dfs2(adj, vis, node, it, maxsize);
			}
		}
	}
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<int> ans(n);
		vector<vector<int>> adj(n);
		for (auto &it : edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		vector<int> vis(n);
		dfs(adj, 0, vis);
		int maxsize = mb[0].first;
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
		}
		vis[0] = 1;
		for (auto &it : adj[0]) {
			dfs2(adj, vis, 0, it, maxsize);
		}
		for (auto &it : mb) {
			ans[it.first] = it.second.second;
		}

		return ans;
	}
};