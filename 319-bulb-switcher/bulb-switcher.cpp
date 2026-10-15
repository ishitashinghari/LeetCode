class Solution {
public:
    int bulbSwitch(int n) {
        int i=1;
        int c=0;
        while(i*i<=n){
            i++;
            c++;
        }
        return c;
    }
};