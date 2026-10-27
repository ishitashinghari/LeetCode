class Solution {
public:
    int f(vector<int>& nums, int i,int pi,vector<vector<int>>& dp){
        if(i==nums.size()) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        int m=0+f(nums,i+1,pi,dp);
        if(pi==-1 || nums[pi]<nums[i])
        m=max(m,1+f(nums,i+1,i,dp));
        return dp[i][pi+1]=m;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
    }
};