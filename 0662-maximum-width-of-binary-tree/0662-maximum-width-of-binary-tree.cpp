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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long,TreeNode*>> q;
        q.push({0,root});
        pair<long long,TreeNode*> temp;
        int maxwidth=0;
        while(!q.empty()){
            int L=0,R=0,s=q.size();
            int minidx=q.front().first;
            for(int i=0 ; i<s ; i++){
                temp=q.front();
                q.pop();
                TreeNode *n=temp.second;
                long long x=temp.first-minidx; //x is current index
                if(i==0) L=x;
                if(i==s-1)R=x;
                if(n->left){
                    q.push({2*x,n->left});
                }
                if(n->right){
                    q.push({2*x+1,n->right});
                }

            }
            maxwidth=max(maxwidth,R-L+1);
        }
        return maxwidth;
    }
};