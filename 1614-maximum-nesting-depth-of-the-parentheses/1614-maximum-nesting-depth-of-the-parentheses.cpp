class Solution {
public:
    int maxDepth(string s) {
        stack <int> st;
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') st.pop();

            int sz=st.size();
            ans = max(ans,sz);
        }
        return ans;
    }
};