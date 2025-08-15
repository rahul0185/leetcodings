class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n = nums.size();
        unordered_map<int,int> freq;


        for(int s : nums) {
            freq[s]++;
        }
         for(int s : nums) {
           if(freq[s]==1)return s;
        }
     return -1; 
    }
};