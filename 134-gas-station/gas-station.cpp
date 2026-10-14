class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int g=0,c=0;
        for(int i=0;i<n;i++){
            g+=gas[i];
            c+=cost[i];
        }
        if(g<c) return -1;
        c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            c+=gas[i]-cost[i];
            if(c<0)
            {
                c=0;
                ans=i+1;
            }
        }
        return ans;
    }
};