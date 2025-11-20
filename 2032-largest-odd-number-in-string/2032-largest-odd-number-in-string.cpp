#include <string>

class Solution {
public:
    std::string largestOddNumber(std::string num) {
        for (int i = (int)num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 == 1) {       // explicit parity check
                return num.substr(0, i + 1);    // take whole prefix up to that odd digit
            }
        }
        return "";
    }
};
