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
    bool helper(TreeNode* root , long long lower , long long upper){
        if(!root) return true;
        if(root->val >= upper || root->val <= lower) return false;
        return  helper(root->left , lower , root->val) && helper(root->right ,root->val, upper) ;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root , INT_MIN - 1LL , INT_MAX +1LL);
    }
};