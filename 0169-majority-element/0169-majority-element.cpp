class Solution {
public:
    int count(vector<int>& nums, int maj, int left, int right){
            int times = 0;
            for(int i = left; i <= right; i++){
                if(nums[i] == maj){
                    times += 1;
                }
            }
            return times;
        }
    int major(vector<int>& nums, int left, int right)
    {
        
        if(left == right){
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftmajor = major(nums, left, mid);
        int rightmajor = major(nums, mid + 1, right);
        if(leftmajor == rightmajor){
            return leftmajor;
        }
        int leftcount = count(nums, leftmajor, left, mid);
        int rightcount = count(nums, rightmajor, mid + 1, right);
        if(leftcount > rightcount){
            return leftmajor;
        }
        else{
            return rightmajor;
        }
    } 
    int majorityElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        return major(nums, left, right);
    }
};