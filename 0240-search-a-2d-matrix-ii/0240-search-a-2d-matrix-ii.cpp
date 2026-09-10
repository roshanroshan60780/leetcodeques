class Solution {
private:
    bool BS(vector<int>& vec, int target){
        int low=0;
        int high=vec.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(vec[mid]==target) return true;
            if(vec[mid]>target) high=mid-1;
            else low=mid+1;

        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0 ;i<m ; i++){
            if(target<matrix[i][0]) return false;
            if(target>matrix[i][n-1]) continue;
            if(BS(matrix[i],target)) return true;
        }
        return false;
    }
};