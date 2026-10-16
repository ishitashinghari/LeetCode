class Solution {
public:
    vector<vector<int>> ind = {{1,3},{0,2,4},{1,5},{0,4},{3,1,5},{2,4}};

    int bfs(string &s,int i){
        queue<pair<string,int>> q;
        q.push({s,i});
        set<string> st;
        st.insert(s);
        int l=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto p=q.front();
                q.pop();
                string str=p.first;
                i=p.second;
                if(str=="123450")
                return l;
                for(int v:ind[i]){
                    string s1=str;
                    swap(s1[i],s1[v]);
                    if(st.find(s1)==st.end())
                    {
                        q.push({s1,v});
                        st.insert(s1);
                    }
                }
            }
            l++;
        }
        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string s="";
        int i;
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                s.push_back('0'+board[j][k]);
                if(s.back()=='0')
                i=s.size()-1;
            }
        }
        return bfs(s,i); 
    }
};