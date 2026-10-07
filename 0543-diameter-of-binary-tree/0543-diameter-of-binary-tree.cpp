class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        isHeight(root);
        return ans;
    }
    int isHeight (TreeNode* root){
        if (root == NULL) return 0;

        int lh = isHeight(root->left);
        int rh = isHeight(root->right);

        ans = max (ans, lh + rh);
        return max(lh, rh) + 1;
    }
};