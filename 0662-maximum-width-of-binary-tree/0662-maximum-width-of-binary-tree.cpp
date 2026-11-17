
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {

            int size = q.size();

            unsigned long long first, last;

            unsigned long long minIndex = q.front().second;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;

                q.pop();

                index = index - minIndex;

                if (i == 0) first = index;

                if (i == size - 1) last = index;

                if (node->left)
                    q.push({node->left, 2 * index});

                if (node->right)
                    q.push({node->right, 2 * index + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};
