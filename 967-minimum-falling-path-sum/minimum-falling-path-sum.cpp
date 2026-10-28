class Solution {
public:
    // int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    //     int m=matrix[0].size();
    //     if(j<0 || j>=m) return INT_MAX;
    //     if(i>=matrix.size()) return 0;
    //     if(dp[i][j]!=INT_MAX) return dp[i][j];
    //     int rd=f(i+1,j+1,matrix,dp);
    //     int d=f(i+1,j,matrix,dp);
    //     int ld=f(i+1,j-1,matrix,dp);
    //     return dp[i][j]=min(ld,min(d,rd))+matrix[i][j];
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                int rd=INT_MAX;
                if(j<m-1)
                rd=dp[i+1][j+1];
                int d=dp[i+1][j];
                int ld=INT_MAX;
                if(j>0)
                ld=dp[i+1][j-1];
                dp[i][j]=min(ld,min(d,rd))+matrix[i][j];
            }
        }
        for(int i=0;i<m;i++)
        ans=min(ans,dp[0][i]);
        return ans;
    }
};