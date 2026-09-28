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
void rec(TreeNode* root,int &count,int va){
    if(root==NULL){
        return;
    }
    if(root->val>=va){
       count++;
       va=root->val;
    }

    rec(root->left,count,va);
    rec(root->right,count,va);
}
    int goodNodes(TreeNode* root) {
        int count=0;
        int va=root->val;
        rec(root,count,va);
        return count;
    }
};