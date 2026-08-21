class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n<=2) return max(nums[0],nums[1]);

        //last element is picked
        int t2=0;
        int t1=nums[1];
        for(int i=2 ; i<n ; i++){
            int temp=max(nums[i]+t2,t1);
            t2=t1;
            t1=temp;
        }
        int pick=t1;

        //when last element is not picked
        t2=nums[0];
        t1=max(nums[0],nums[1]);
        for(int i=2 ; i<n-1 ; i++){
            int temp=max(nums[i]+t2,t1);
            t2=t1;
            t1=temp;
        }
        int notpick=t1;
        return max(pick,notpick);
    }
};