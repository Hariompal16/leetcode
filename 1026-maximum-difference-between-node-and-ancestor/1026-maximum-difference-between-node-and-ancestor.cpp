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
int tree(TreeNode* root,int maxx,int minn){
    if(root==NULL){
        return maxx-minn;
    }

    maxx=max(maxx,root->val);
    minn=min(minn,root->val);
  int left=tree(root->left,maxx,minn);
    int right=tree(root->right,maxx,minn);
    return max(left,right);
}
    int maxAncestorDiff(TreeNode* root) {
       return tree(root,root->val,root->val);
    }
};