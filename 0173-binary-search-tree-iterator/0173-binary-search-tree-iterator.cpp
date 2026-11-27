class BSTIterator {
public:
    
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushALL(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        
        pushALL(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushALL(TreeNode* node){

        while(node != NULL){
            st.push(node);
            node= node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */