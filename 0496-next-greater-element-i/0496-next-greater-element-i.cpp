class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);

        for (int i = 0; i < nums1.size(); i++) {
            int x = nums1[i];

            // find x in nums2
            int pos = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == x) {
                    pos = j;
                    break;
                }
            }

            // look to the RIGHT of pos for first greater
            for (int j = pos + 1; j < nums2.size(); j++) {
                if (nums2[j] > x) {
                    ans[i] = nums2[j];
                    break;          // very important
                }
            }
        }

        return ans;
    }
};
