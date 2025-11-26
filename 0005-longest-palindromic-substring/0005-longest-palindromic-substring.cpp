class Solution {
public:
    string longestPalindrome(string s) {
       /* int n = s.length();
        if(n <= 1) return s;
        int max_len = 1;
        int st = 0, end = 0;
        int i = 0;
        if(n % 2 == 0){
            for(i = 0; i < n-1; i++){
                int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--,r++;
                }
                else{
                    break;
                }
                int len = r-l-1;
                if(len > max_len){
                    max_len = len;
                    st = l+1;
                    end = r-1;
                }
            }
        } 
        }
        else{
            for(i = 0; i < n-1; i++){
                int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--,r++;
                }
                else{
                    break;
                }
                int len = r-l-1;
                if(len > max_len){
                    max_len = len;
                    st = l+1;
                    end = r-1;
                }
            }
        }
        }

        return s.substr(st,max_len);
        */
        int n = s.length();
        if (n <= 1) return s;

        int max_len = 1;
        int start = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            int len = r - l - 1;   // length of palindrome
            if (len > max_len) {
                max_len = len;
                start = l + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            // odd-length palindrome, center at i
            expand(i, i);
            // even-length palindrome, center between i and i+1
            expand(i, i + 1);
        }

        return s.substr(start, max_len);
    }
};