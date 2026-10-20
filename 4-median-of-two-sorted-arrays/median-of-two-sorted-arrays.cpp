class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v=nums1;
        for(int i=0;i<nums2.size();i++)
        v.push_back(nums2[i]);
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2)
        return (double) v[n/2];
        else
        {
            double a=v[n/2-1];
            double b=v[n/2];
            return (a+b)/2;
        }
    }
};