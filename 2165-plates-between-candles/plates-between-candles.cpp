class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> ans;
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        vector<int> p(n,0);
        if(s[0]=='|') l[0]=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='|') l[i]=i;
            else l[i]=l[i-1];
        }
        if(s[n-1]=='|') r[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='|') r[i]=i;
            else r[i]=r[i+1];
        }
        if(s[0]=='*') p[0]=1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='*')
            p[i]=p[i-1]+1;
            else
            p[i]=p[i-1];
        }
        for(auto q:queries){
            int left =r[q[0]];
            int right = l[q[1]];
            if(right!=-1 && left!=-1 && right-left>1)
            ans.push_back(p[right]-p[left]);
            else
            ans.push_back(0);
        }
        return ans;
    }
};