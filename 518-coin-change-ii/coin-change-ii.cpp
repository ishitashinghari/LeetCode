class Solution {
public:
    int f(int amount,vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(i==coins.size()-1)
        {
            if(amount%coins[i]==0) return 1;
            else return 0;
        }
        if(i>=coins.size()) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0+f(amount-coins[i],coins,i,dp);
        int ntake=f(amount,coins,i+1,dp);
        return dp[i][amount]=take+ntake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return f(amount,coins,0,dp);
    }
};