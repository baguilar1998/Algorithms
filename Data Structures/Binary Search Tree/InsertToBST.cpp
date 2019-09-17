class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        int currentVal = root->val;
        TreeNode *left = root->left, *right = root->right;
        if(currentVal > val) {
            if (left != NULL)
                insertIntoBST(left,val);
            else {
                root->left = new TreeNode(val);
            }
        }
        else if(currentVal < val) {
            if (right != NULL)
                insertIntoBST(right,val);
            else {
                root->right = new TreeNode(val);
            }
        }
        return root;
    }
};