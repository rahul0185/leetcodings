class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Traverse each character index of the first word
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];   // character to match

            // Check this character in all other words
            for (int j = 1; j < strs.size(); j++) {
                // If index out of range OR mismatch → stop
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }

        // If entire first word is common prefix
        return strs[0];
    }
};
