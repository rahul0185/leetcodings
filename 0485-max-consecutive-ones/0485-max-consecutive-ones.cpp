class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
    int j = 0;
    int k = 0;
    for(int i = 0; i < n ; i++){
        if(nums[i] == 1){
            j += 1;
        }
        else if(nums[i] == 0){
            if(j>k){
                k = j;
                j = 0;
            }
            else{
                j = 0;
            }
        }    
    } 
    if(j>k){
        k = j;
    } 
    return k;
    }
};