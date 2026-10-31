class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int N:nums){
            mp[N]++;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i:s){
            pq.push({mp[i],i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};