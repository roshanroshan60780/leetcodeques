class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; ; j++){
                int streakpoints=j*(j+1)/2;
                if(streakpoints>i) break;
                dp[i]=min(dp[i],j+1+dp[i-streakpoints]);  //currstreak + skip + prevstreak
            }
        }
        return dp[n]-1;  //when it is first streak then no skip should be added but we add that that's why -1
    }
};