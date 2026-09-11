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
    void traverse(TreeNode* root, vector<int>& inorder){
        if(!root) return;
        traverse(root->left,inorder);
        inorder.push_back(root->val);
        traverse(root->right,inorder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traverse(root,inorder);
        int n=inorder.size();
        if(n==1) return false;
        int i=0, j=n-1;
        while(i<j){
            int s=inorder[i]+inorder[j];
            if(s==k) return true;
            else if(s<k) i++;
            else j--;
        }
        return false;
    }
};