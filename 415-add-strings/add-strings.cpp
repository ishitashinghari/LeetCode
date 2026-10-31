class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.size()-1,j=num2.size()-1;
        int s=0,c=0;
        while(i>=0 && j>=0){
            int a=num1[i]-'0';
            int b=num2[j]-'0';
            int n=a+b+c;
            s=n%10;
            c=n/10;
            ans+=to_string(s);
            i--;
            j--;
        }
        while(i>=0){
            int n=num1[i]-'0'+c;
            ans+=to_string(n%10);
            c=n/10;
            i--;
        }
        while(j>=0){
            int n=num2[j]-'0'+c;
            ans+=to_string(n%10);
            c=n/10;
            j--;
        }
        if(c>0)
        ans+=to_string(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};