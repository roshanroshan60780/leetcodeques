class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> row(n,0);
        row[0]=triangle[0][0];
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=i ; j++){
                if(j==0){
                    row[j]=triangle[i][j]+row[j];
                }
                else if(j==i){
                    row[j]=triangle[i][j]+row[j-1];
                }
                else {
                    row[j]=min(row[j],row[j-1]) + triangle[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(row[i]<ans) ans=row[i];
        }
        return ans;
    }
};