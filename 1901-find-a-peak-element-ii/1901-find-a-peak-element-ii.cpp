class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int maxfirstcol=0;
        for(int i=0 ; i<m ; i++){
            if(mat[i][0]>mat[maxfirstcol][0]) maxfirstcol=i;
        }

        if(n==1) return {maxfirstcol,0};
        if(mat[maxfirstcol][0]>mat[maxfirstcol][1]) return {maxfirstcol,0};

        int maxlastcol=0;
        for(int i=0 ; i<m ; i++){
            if(mat[i][n-1]>mat[maxlastcol][n-1]) maxlastcol=i;
        }
        if(mat[maxlastcol][n-1]>mat[maxlastcol][n-2]) return {maxlastcol,n-1};
        int low=1,high=n-2;
        while(low<=high){
            int maxidx=0;
            int mid=(low+high)/2;
            for(int i=0 ; i<m ; i++){
                if(mat[maxidx][mid]<mat[i][mid]) maxidx=i;
            }
            if(mat[maxidx][mid-1]<mat[maxidx][mid] && mat[maxidx][mid+1]<mat[maxidx][mid]) return {maxidx,mid};
            if(mat[maxidx][mid+1]<mat[maxidx][mid]) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};