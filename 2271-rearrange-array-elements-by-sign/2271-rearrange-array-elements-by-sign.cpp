class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> pos;
        vector <int> neg;
        int p = 0;
        int q = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        for(int i = 0; i < n; i++){
            if (i % 2 == 0){
                nums[i] = pos[p++];
            }
            else {
                nums[i] = neg[q++];
            }
        }
        return nums;
    }
};