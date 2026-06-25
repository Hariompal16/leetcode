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
    void tree(TreeNode* root, int val, int depth,int node){
        if(root==NULL){
            return;
        }
        if(node==depth-1){
           TreeNode* lefttree=new TreeNode(val);
          TreeNode* righttree=new TreeNode(val);
            lefttree->left=root->left;
            righttree->right=root->right;
            root->left=lefttree;
            root->right=righttree;
            return;
        }
        tree(root->left,val,depth,node+1);
        tree(root->right, val, depth,node+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
          TreeNode* newRoot=new TreeNode(val);
           newRoot->left=root;
           return newRoot;
        }
        tree(root,val,depth,1);
          return root;
    }
};