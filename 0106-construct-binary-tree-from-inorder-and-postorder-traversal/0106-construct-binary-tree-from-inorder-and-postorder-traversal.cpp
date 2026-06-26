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
int find(int index,vector<int>& inorder,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==index) return i;
    }
    return -1;
}
TreeNode* tree(vector<int>& inorder, vector<int>& postorder,int index,int start,int end){
    
  if(start>end) return NULL;
    TreeNode* root=new TreeNode(postorder[index]);
    int pos=find(postorder[index],inorder,start,end);
    root->right=tree(inorder,postorder,index-1,pos+1,end);
    root->left=tree(inorder,postorder,index-(end-pos)-1,start,pos-1);
    return root;
} 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start=0;
        int end=inorder.size()-1;
        int index=postorder.size()-1;
      return tree(inorder,postorder,index,start,end);
    }
};