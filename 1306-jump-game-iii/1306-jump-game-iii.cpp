class Solution {
private:
    bool func(int i ,int lastidx ,  vector<int>& arr , vector<int>& visited){
        if(visited[i]) return false;
        
        if(arr[i]==0) return true;
        int nidx1=i+arr[i],nidx2=i-arr[i];
        int n=arr.size();
        visited[i]=1;
        bool temp1=false,temp2=false;
        if(nidx1>=0 && nidx1<n && nidx1!=lastidx) temp1=func(nidx1,i,arr,visited);
        if(nidx2>=0 && nidx2<n && nidx2!=lastidx) temp2=func(nidx2,i,arr,visited);
        return temp1 || temp2;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> visited(n,0);
        return func(start,-1,arr,visited);
    }
};