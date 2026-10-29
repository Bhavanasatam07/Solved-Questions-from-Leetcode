
class Solution {
public:
    map<int, vector<pair<int, int>>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (root == NULL) {
            return;
        }

        nodes[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        nodes.clear();

        dfs(root, 0, 0);

        vector<vector<int>> ans;

        for (auto &entry : nodes) {
            vector<pair<int, int>> v = entry.second;

            sort(v.begin(), v.end());

            vector<int> column;

            for (int i = 0; i < v.size(); i++) {
                column.push_back(v[i].second);
            }

            ans.push_back(column);
        }

        return ans;
    }
};
