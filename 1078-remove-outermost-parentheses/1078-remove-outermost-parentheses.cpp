class Solution {
public:
    string removeOuterParentheses(string s) {
        string arr;
        int open = 0;
        int n = s.size();
        for(int i = 0; i < n ; i++) {
            if (s[i] == '('){
                if(open > 0){
                    arr.push_back(s[i]);
                }
                open++;
            }
            else{
                open--;
                if(open >0){
                    arr.push_back(s[i]);
                }
            }
        }
        return arr;
    }
};