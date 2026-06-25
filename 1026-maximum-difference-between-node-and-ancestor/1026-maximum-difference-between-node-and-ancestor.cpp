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
public:
   int maxdiff;
    void maxdiffutil(TreeNode * root,TreeNode* child){
        if(root==NULL|| child==NULL){
            return;
        }
        maxdiff=max(maxdiff,abs(root->val - child->val));
        maxdiffutil(root,child->left);
        maxdiffutil(root,child->right);
    }

    void maxdi(TreeNode* root){
        if(root==NULL){
            return;
        }
        maxdiffutil(root,root->left);
        maxdiffutil(root,root->right);
     
   maxdi(root->left);
   maxdi(root->right);

    }
    int maxAncestorDiff(TreeNode* root) {
        maxdiff=-1;
        maxdi(root);
        return maxdiff;
    }
};