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
    bool helper(TreeNode* L , TreeNode* R){
        if(R==nullptr || L==nullptr) return L==R;
        return L->val == R->val && helper(L->left,R->right) && helper(L->right , R->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left , root->right);
    }
};