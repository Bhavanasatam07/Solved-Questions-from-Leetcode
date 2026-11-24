class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL ){
            return NULL;
        }
        if (root->val > key){
            root->left = deleteNode(root->left , key);
        }
        else if (root->val < key){
            root->right = deleteNode(root->right , key);
        }
        else {
            if(root->right == NULL){
                return root->left;
            }
            
            if(root->left == NULL){
                return root->right;
            }

            TreeNode* successor = root->right;
            while ( successor->left != NULL){
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right,successor->val);

        }
        return root;
    }
};