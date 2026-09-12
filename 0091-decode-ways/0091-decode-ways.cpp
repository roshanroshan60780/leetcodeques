class Solution {
private:
    int func(int i, string& s , vector<int>& dp){
        int n=s.size();
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=func(i+1,s,dp);
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) ans+=func(i+2,s,dp);
        return dp[i]=ans;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return func(0,s,dp);
    }
};