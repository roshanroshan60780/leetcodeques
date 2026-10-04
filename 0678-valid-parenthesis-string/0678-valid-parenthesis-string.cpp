class Solution {
    bool helper(string &s , int idx , int balance,vector<vector<int>> & dp){
        if(idx == s.size()){
            if(balance==0) dp[idx][balance]=1;
            else dp[idx][balance]=0;
            return dp[idx][balance];
        }
        if(balance<0) return false;
        if(dp[idx][balance]!=-1) return dp[idx][balance];
        
        if(s[idx]=='(') {dp[idx][balance]=helper(s,idx+1,balance+1,dp);return dp[idx][balance];}
        if(s[idx]==')'){
            if(balance==0) dp[idx][balance]=0;
            else  dp[idx][balance]=helper(s,idx+1,balance-1,dp);
            return dp[idx][balance];
        }
        else{
            if(balance==0) dp[idx][balance] = helper(s,idx+1,balance+1,dp) || helper(s,idx+1,balance,dp);
            else dp[idx][balance] = helper(s,idx+1,balance-1,dp) || helper(s,idx+1,balance+1,dp) || helper(s,idx+1,balance , dp);
            return dp[idx][balance];
        }
    }
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return helper(s,0,0,dp);
    }
};