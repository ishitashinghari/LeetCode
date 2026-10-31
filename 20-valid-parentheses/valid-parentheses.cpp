class Solution {
public:
    bool isMatchingPair(char open, char close) 
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else 
            {
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();
                if(!isMatchingPair(ch,s[i])) return false;
            }
        }
        return st.empty();
    }
};