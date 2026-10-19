class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n=words.size();
        if(n<2) return 0;
        int c=0;
        set<char> s;
        set<char> s1;
        for(int i=0;i<n;i++){
            for(char &ch:words[i])
            s.insert(ch);
            for(int j=i+1;j<n;j++){
                for(char &c1:words[j]){
                    s1.insert(c1);
                }
                if(s==s1) c++;
                s1.clear();
            }
            s.clear();
        }
        return c;
    }
};