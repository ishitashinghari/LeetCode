class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int M=1000000007;
        int n=inventory.size();
        sort(inventory.rbegin(),inventory.rend());
        long long ans=0;
        for(int i=0;orders>0 && i<n;i++){
            long long m=inventory[i];
            long long next=0;
            if(i+1 < n)
            next=inventory[i+1];
            long long c=i+1;
            long long a=(m-next)*c;
            long long s=min((long long)orders,a);
            long long f=s/c;
            long long r=s%c;
            ans=ans+((m+m-f+1)*f/2%M*c)%M;
            ans=ans+(m-f)*r;
            orders-=s;
        }
        return ans%M;
    }
};