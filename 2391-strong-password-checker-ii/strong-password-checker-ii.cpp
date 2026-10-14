class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n=password.size();
        if(n<8) return false;
        int l=0,u=0,d=0,s=0;
        if(islower(password[0]))
        l=1;
        else if(isupper(password[0]))
        u=1;
        else if(isdigit(password[0]))
        d=1;
        else 
        s=1;
        for(int i=1;i<n;i++){
            if(password[i]==password[i-1]) return false;
            if(islower(password[i]))
            l=1;
            else if(isupper(password[i]))
            u=1;
            else if(isdigit(password[i]))
            d=1;
            else 
            s=1;
        }
        if(!l || !u || !d || !s) return false;
        else return true;
    }
};