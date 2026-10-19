class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int r[4]={1,-1,0,0};
        int c[4]={0,0,1,-1};
        int ma=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                    int count=0;
                    while(!q.empty()){
                        auto p=q.front();
                        int row=p.first;
                        int col=p.second;
                        q.pop();
                        count++;
                        for(int k=0;k<4;k++){
                            if(row+r[k]<n && row+r[k]>=0 && col+c[k]>=0 && col+c[k]<m && grid[row+r[k]][col+c[k]]==1)
                            {
                                q.push({row+r[k],col+c[k]});
                                grid[row+r[k]][col+c[k]]=0;
                            }
                        }
                    }
                    ma=max(ma,count);
                }
            }
        }
        if(ma!=INT_MIN) return ma;
        else return 0;
    }
};