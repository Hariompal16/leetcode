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

void rec(TreeNode* root,int steps,bool goleft){
   if(root==NULL){
    return;
   }

   maxx=max(maxx,steps);
   if(goleft==true){
    rec(root->left,steps+1,false);
    rec(root->right,1,true);
   }
   else{
    rec(root->right,steps+1,true);
    rec(root->left,1,false);
   }
}
    int longestZigZag(TreeNode* root) {
       rec(root,0,true);
       rec(root,0,false);
        return maxx;
    }
};