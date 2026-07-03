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
private:
    int findidx(vector<int>& arr , int target){
        for(int i=0 ; i<arr.size() ; i++) if(arr[i]== target) return i;
        return 0;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int ps ,int pe , int is,int ie){
        if(ps>pe || is>ie) return NULL;
        if(ps==pe) return new TreeNode(preorder[ps]);
        TreeNode* root = new TreeNode(preorder[ps]);
        int pidx=findidx(inorder , preorder[ps]);  //pidx is pivot index of inorder traversal;
        int LPS=pidx-is; //left part size of pivot in inorder traversal
        int RPS=ie-pidx; //right part size of pivot in inorder traversal
        TreeNode* L= helper(preorder, inorder , ps+1 , ps+LPS , is , pidx-1);
        TreeNode* R= helper(preorder , inorder, ps+LPS+1 , pe , pidx+1 , ie);
        root->left=L;
        root->right=R;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int size=preorder.size();
        root = helper(preorder,inorder,0,size-1,0,size-1);
        return root;
    }
};