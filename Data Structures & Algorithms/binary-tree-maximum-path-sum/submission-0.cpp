/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int res = INT_MIN;
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftmax = dfs(root->left);
        int rightmax = dfs(root->right);
        leftmax = max(leftmax,0);
        rightmax = max(rightmax,0);
        res  = max(res,root->val+leftmax+rightmax);
        return root->val + max(rightmax,leftmax);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
        
    }
};
