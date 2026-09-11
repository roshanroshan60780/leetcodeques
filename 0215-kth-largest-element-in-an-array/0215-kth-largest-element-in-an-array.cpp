class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x : nums){
            if(pq.size()<k){
                pq.push(x);
            }
            else{
                pq.push(x);
                pq.pop();
            }
        }
        return pq.top();
    }
};