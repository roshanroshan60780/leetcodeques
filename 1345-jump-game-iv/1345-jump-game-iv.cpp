class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        int n=arr.size();
        for(int i=0 ; i<n ; i++){
            mp[arr[i]].push_back(i);
        }
        queue<pair<int,int>> q; //{idx,steps}
        q.push({0,0});
        vector<int> visited(n,0);
        visited[0]=1;
        while(!q.empty()){
            int qs=q.size();
            for(int i=0 ; i<qs ; i++){
                auto temp= q.front();
                q.pop();
                int idx=temp.first;
                int steps=temp.second;
                if(idx==n-1){
                    return steps;
                }
                if(idx>0 && !visited[idx-1]){
                    q.push({idx-1,steps+1});
                    visited[idx-1]=1;
                }
                if(idx<n-1 && !visited[idx+1]){
                    q.push({idx+1,steps+1});
                    visited[idx+1]=1;
                }
                vector<int>& same=mp[arr[idx]];
                for(int j=same.size()-1 ; j>=0 ; j--){
                    if(same[j]!=idx && !visited[same[j]]){
                        q.push({same[j],steps+1});
                        visited[same[j]]=1;
                    }
                }
                mp[arr[idx]].clear();
            }
        }
        return 0;
    }
};