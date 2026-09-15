class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<int> vec;
        for(int i=0 ; i<n; i++){
            int x=0;
            for(int j=0 ;j<n ; j++){
                if(nums[i][j]=='1'){
                    int pos=n-j-1;
                    x= x | 1<<pos;
                }
            }
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(i<n){
            if(i!=vec[i]) break;
            i++;
        }
        string ans;
        for(int j=0 ;j<n ; j++){
            int pos=n-j-1;
            if(i & 1<<pos) ans.push_back('1');
            else ans.push_back('0');
        }
        return ans;
    }
};