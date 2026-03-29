class Solution {
    int quickselect(vector<int>& nums, int left, int right, int k){
        int pivot = nums[right], p = left , i;

        for(i = left; i < right; i++ ){
            if(nums[i] > pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[right]);

        if(p == k){
            return nums[p];
        }
        else if(p < k){
            return quickselect(nums, p + 1, right, k);
        }
        else{
            return quickselect(nums, left, p - 1, k);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }
};