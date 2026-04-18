class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int end = 0;
        int farthest = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);
            
            if(i == end){
                steps++;
                end = farthest;
            }
        }
        
        return steps;
    }
};