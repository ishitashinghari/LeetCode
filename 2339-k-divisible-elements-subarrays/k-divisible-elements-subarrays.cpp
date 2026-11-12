class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            vector<int> t;
            int c=0;
            for(int j=i;j<n;j++){
                t.push_back(nums[j]);
                if(nums[j]%p==0)
                c++;
                if(c>k)
                break;
                s.insert(t);
            }
        }
        return s.size();
    }
};