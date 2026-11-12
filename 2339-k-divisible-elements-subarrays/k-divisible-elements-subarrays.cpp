class Solution {
public:
    class TrieNode {
        public:
        unordered_map<int,TrieNode*> mp;
    };

    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        TrieNode* rt=new TrieNode();
        int c=0;
        for(int i=0;i<n;i++){
            TrieNode* curr=rt;
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0)
                count++;
                if(count>k)
                break;
                if(curr->mp.find(nums[j])==curr->mp.end())
                {
                    curr->mp[nums[j]]=new TrieNode();
                    c++;
                }
                curr=curr->mp[nums[j]];
            }
        }
        return c;
    }
};