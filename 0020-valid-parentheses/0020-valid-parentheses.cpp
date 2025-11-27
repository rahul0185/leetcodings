/*class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        if(s.size() < 1) return false;
        */
        /*for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') p.push(s[i]);
            else if(s[i] == '{') c.push(s[i]);
            else if(s[i] == '[') b.push(s[i]);
            else if(!p.empty() && s[i] == ')' && p.top() == '(') return true; 
            else if(!c.empty() && s[i] == '}' && c.top() == '{') return true; 
            else if(!b.empty() && s[i] == ']' && b.top() == '[') return true; 
            else return false;  
        }
        */
        /*for(int i = 0; i < s.size(); i++){
            if(s[i] == '(','{','[') p.push(s[i]);
            else if(s[i] == ')' && p.top() == '('){ 
            p.pop();
            return true;}
            else if(s[i] == '}' && p.top() == '}') 
            {
                p.pop();
                return true;
            }
            else if(s[i] == ']' && p.top() == ']'){ 
                p.pop();
                return true;
            }
            else return false;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch : s) {
            // If opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                // Closing bracket: stack must not be empty
                if (st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                // Check matching type
                if (ch == ')' && top != '(') return false;
                if (ch == '}' && top != '{') return false;
                if (ch == ']' && top != '[') return false;
            }
        }
        
        // Valid only if no unmatched openings remain
        return st.empty();
    }
};
