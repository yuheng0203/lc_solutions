class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] - a[0] < b[1] - b[0];
        });

        int total = 0;

        for(int i = 0; i < costs.size(); i++){
            if(i < n){
                total += costs[i][1];
            } else {
                total += costs[i][0];
            }
        }

        return total;
    }
};