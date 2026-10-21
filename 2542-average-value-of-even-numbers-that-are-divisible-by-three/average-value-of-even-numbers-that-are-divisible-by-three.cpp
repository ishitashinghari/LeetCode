class Solution {
public:
    int averageValue(vector<int>& nums) {
        int s=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0 && nums[i]%3 == 0)
            {
                s+=nums[i];
                c++;
            }
        }
        if(c)
        return s/c;
        else
        return 0;
    }
};