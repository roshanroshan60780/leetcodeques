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
    void helperdown(TreeNode* curr , int k , int d ,vector<int> & ans){
        if(!curr) return;
        if(d==k){
            ans.push_back(curr->val);
            return;
        }
        helperdown(curr->left , k , d+1 , ans );
        helperdown(curr->right , k , d+1 , ans);
    }
    void helperup(TreeNode* curr , TreeNode* root, int k , int d , unordered_map<TreeNode* , TreeNode*>& parent , vector<int> & ans){
        if(curr==root) return;
        TreeNode* p=curr;
        while(d<k && p!=root){
            d++; // distance increase by 1 when we go to parent of p
            if(d==k){
                ans.push_back(parent[p]->val);
                return;
            }
            if(parent[p]->left != p) helperdown(parent[p]->left , k , d+1 , ans);
            else helperdown(parent[p]->right , k , d+1 , ans);
            
            p=parent[p];
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            parent[temp->left]=temp;
            parent[temp->right]=temp;
        }
        vector<int> ans;
        helperdown(target , k , 0 , ans);
        helperup(target , root , k , 0 , parent , ans);
        return ans;
    }
};