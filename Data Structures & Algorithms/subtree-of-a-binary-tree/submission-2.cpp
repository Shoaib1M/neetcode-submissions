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
    bool sametree(TreeNode* root,TreeNode* subroot){
        if(root == NULL && subroot==NULL){
            return true;
        }
        if(root && subroot && root->val == subroot->val){
            return (sametree(root->left,subroot->left)&&sametree(root,subroot->right));
        }
        else{
            return false;
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(subroot == NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        
        if(sametree(root,subroot)){
            return true;
        }
        return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);        
    }
};
