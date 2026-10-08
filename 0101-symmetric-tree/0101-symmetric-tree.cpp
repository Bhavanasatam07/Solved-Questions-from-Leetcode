
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || symmetrichelp(root->left, root->right);
    }

    bool symmetrichelp(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL)
            return left == right;

        if (left->val != right->val)
            return false;

        return symmetrichelp(left->left, right->right) &&
               symmetrichelp(left->right, right->left);
    }
};
