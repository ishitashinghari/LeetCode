class Solution {
public:
    int f(vector<int>& prices,int i,int b,vector<vector<vector<int>>>& dp,int c,int k){
        if(i==prices.size() || c==k) return 0;
        if(dp[i][b][c]!=-1) return dp[i][b][c];
        int p=0;
        if(b)
        p=max(-prices[i]+f(prices,i+1,0,dp,c,k),f(prices,i+1,1,dp,c,k));
        else
        p=max(prices[i]+f(prices,i+1,1,dp,c+1,k),f(prices,i+1,0,dp,c,k));
        return dp[i][b][c]=p;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2, vector<int> (k,-1)));
        return f(prices,0,1,dp,0,k);
    }
};