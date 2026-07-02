/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> pathp,pathq;
    void nodepath(TreeNode* root , TreeNode* p, TreeNode* q , vector<TreeNode*>& path){
        if(!pathp.empty() && !pathq.empty()) return;
        if(!root) return;
        path.push_back(root);
        if(root==q) pathq=path;
        if(root==p) pathp=path;
        if(root->left){
            nodepath(root->left,p,q,path);
            path.pop_back();
        }
        if(root->right){
            nodepath(root->right,p,q,path);
            path.pop_back();
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        nodepath(root,p,q,path);
        int sp=pathp.size();
        int sq=pathq.size();
        int i=0;
        for( ; i<min(sp,sq) ; i++){
            if(pathp[i]!=pathq[i]) break;
        }
        return path[i-1];
    }
};