class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ansidx=0;
        int last=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0 ; i<m ; i++){
            int cntone=0;
            for(int j=0 ; j<n ; j++){
                if(mat[i][j]) cntone++;
            }
            if(last<cntone){ansidx=i;last=cntone;}
        }
        return {ansidx,last};
    }
};