/*class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        int n = s.size();
        string temp;
        string ans;

        for (int i = 0; i < n ; i++) {
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }
            
            else{
                if(ans.empty()) {
                    ans = temp;
                    temp.clear();
                }
                else{
                    ans = temp+' '+ans;
                    temp.clear();
                }
            }
            }
        return ans;
     }
};
*/
class Solution {
public:
    string reverseWords(string s) {
        string temp;
        vector<string> words;

        // Extract words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } else {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            }
        }

        // Push the last word if any
        if (!temp.empty()) {
            words.push_back(temp);
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Join words with a single space
        string ans;
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += ' ';
        }

        return ans;
    }
};
