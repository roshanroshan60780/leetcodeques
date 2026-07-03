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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,int ps ,int pe , int is,int ie , unordered_map<int,int> &mp){
        if(ps>pe || is>ie) return NULL;
        if(ps==pe) return new TreeNode(postorder[pe]);
        TreeNode* root = new TreeNode(postorder[pe]);
        int pidx=mp[postorder[pe]];  //pidx is pivot index of inorder traversal;
        int LPS=pidx-is; //left part size of pivot in inorder traversal
        int RPS=ie-pidx; //right part size of pivot in inorder traversal
        TreeNode* L= helper(postorder, inorder , pe-RPS-LPS , pe-RPS-1 , is , pidx-1,mp);
        TreeNode* R= helper(postorder , inorder, pe-RPS , pe-1 , pidx+1 , ie,mp);
        root->left=L;
        root->right=R;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        int size=postorder.size();
        unordered_map<int,int> mp;
        for(int i=0 ; i<size ; i++){
            mp[inorder[i]] = i;
        }
        root = helper(postorder,inorder,0,size-1,0,size-1,mp);
        return root;
    }
};