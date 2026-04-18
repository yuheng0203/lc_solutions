class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == 0){
                bool canPass = false;
                
                for(int j = i - 1; j >= 0; j--){
                    if(nums[j] > i - j){
                        canPass = true;
                        break;
                    }
                }
                
                if(!canPass){
                    return false;
                }
            }
        }
        
        return true;
    }
};