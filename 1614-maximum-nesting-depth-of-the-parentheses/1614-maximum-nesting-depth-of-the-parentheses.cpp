class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0,count = 0;
        for (int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                count++;
            }
            else if(s[i] == ')') {
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};