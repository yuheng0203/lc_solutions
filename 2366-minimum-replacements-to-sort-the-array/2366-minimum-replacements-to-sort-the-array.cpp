class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long int count = 0, mn = 0, n = nums.size() - 1;
        mn = nums[n];
        for (n = nums.size() - 1; n >= 0; n--){
             
            if(nums[n] > mn){
                if(nums[n] % mn == 0){
                    count += (nums[n] / mn) - 1;
                    mn = nums[n] / (nums[n] / mn);
                }
                else{
                    count += nums[n] / mn; 
                    mn = nums[n] / ((nums[n] / mn) + 1);
                }
            }
            if(nums[n] < mn){
                mn = nums[n];
            }
        }
        return count;
    }
};