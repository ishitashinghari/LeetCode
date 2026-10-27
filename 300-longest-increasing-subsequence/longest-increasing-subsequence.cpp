class Solution {
public:
//     int f(vector<int>& nums, int i,int pi,vector<vector<int>>& dp){
//         if(i==nums.size()) return 0;
//         if(dp[i][pi+1]!=-1) return dp[i][pi+1];
//         int m=0+f(nums,i+1,pi,dp);
//         if(pi==-1 || nums[pi]<nums[i])
//         m=max(m,1+f(nums,i+1,i,dp));
//         return dp[i][pi+1]=m;
//     }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int pi=i-1;pi>=-1;pi--){
                int m=0+dp[i+1][pi+1];
                if(pi==-1 || nums[pi]<nums[i])
                m=max(m,1+dp[i+1][i+1]); //add +1 to 2nd state while tabulating
                dp[i][pi+1]=m;
            }
        }
        return dp[0][0];
    }
};