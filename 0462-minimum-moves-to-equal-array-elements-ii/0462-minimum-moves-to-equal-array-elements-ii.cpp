class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        sort(nums.begin(), nums.end());
        int step = 0;
        while(i < j){
            step += nums[j] - nums[i];
            i++;
            j--;
        }
        // if(i == j) step++;
        return step;
    }
};