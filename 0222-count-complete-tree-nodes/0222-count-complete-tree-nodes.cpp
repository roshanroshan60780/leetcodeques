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
    int heightleft(TreeNode* root) {
        int height=0;
        TreeNode* temp=root;
        while(temp){
            height++;
            temp=temp->left;
        }
        return height;
    }
    int heightright(TreeNode* root) {
        int height=0;
        TreeNode* temp=root;
        while(temp){
            height++;
            temp=temp->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=heightleft(root);
        int rh=heightright(root);
        if(lh==rh){
            return (1<<lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};