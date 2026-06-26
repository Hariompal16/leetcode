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
 int maxx;
 void tree(TreeNode* root,int steps,bool goleft){
    if(root==NULL){
        return;
    }
    maxx=max(maxx,steps);
    if(goleft==true){
        tree(root->left,steps+1,false);
        tree(root->right,1,true);
    }
    else{
        tree(root->right,steps+1,true);
        tree(root->left,1,false);
    }
 }
    int longestZigZag(TreeNode* root) {
        tree(root,0,true);
        tree(root,0,false);
        return maxx;
    }
};