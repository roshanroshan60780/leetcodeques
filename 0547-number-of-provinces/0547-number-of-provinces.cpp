class Solution {
private:
    void traverse(vector<vector<int>>& isConnected , int curr , vector<int>& visited ){
        queue<int> q;
        visited[curr]=1;
        q.push(curr);
        int n=isConnected.size();
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0 ; i<n ; i++){
                if(isConnected[temp][i]==1 && !visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n , 0);
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                ans++;
                traverse(isConnected ,i,visited);
            }
        }
        return ans;
    }
};