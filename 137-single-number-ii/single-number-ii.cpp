class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans;
        for(auto p:mp){
            int c=p.second;
            if(c==1)
            {
                ans=p.first;
                break;
            }
        }
        return ans;
    }
};