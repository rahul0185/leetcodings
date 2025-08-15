#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        sort(nums.begin(), nums.end());
        
        int maxCount = 1;      // max length found
        int currentCount = 1;  // current consecutive sequence length

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                // Duplicate number, ignore
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1) {
                // Consecutive number, increment current sequence length
                currentCount++;
            } else {
                // Sequence broken, update maxCount and reset currentCount
                maxCount = max(maxCount, currentCount);
                currentCount = 1;
            }
        }
        // After loop, check last sequence
        maxCount = max(maxCount, currentCount);

        return maxCount;
    }
};