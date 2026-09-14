class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n=matrix.size();
        int pqs=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ;j<n; j++){
                if(pqs<k){
                    pq.push(matrix[i][j]);
                    pqs++;
                }
                else{
                    pq.push(matrix[i][j]);
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};