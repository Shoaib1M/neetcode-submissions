class Solution {
    bool check(TreeNode* root, int right, int left) {
        if (root == nullptr) {
            return true;
        }

        if(!(root->val < right && root->val > left)) {
            return false;
        }

        return check(root->left, root->val, left) &&
               check(root->right, right, root->val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MAX, INT_MIN);
    }
};