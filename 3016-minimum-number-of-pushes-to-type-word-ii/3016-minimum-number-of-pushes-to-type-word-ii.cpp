class Solution {
public:
    int minimumPushes(string word) {
        if(word.size()<=8) return word.size();
        vector<int> mp(26,0);
        for(char ch:word){
            mp[ch-'a']++;
        }
        sort(mp.begin(), mp.end(), greater<int>());
        int temp=0;
        int presses=1;
        int ans=0;
        for(int i=0 ; i<26 ; i++){
            if(mp[i]){
                ans+=presses*mp[i];
                temp++;
                if(temp==8){
                    temp=0 ;
                    presses++;
                }
            }
        }
        return ans;
    }
};