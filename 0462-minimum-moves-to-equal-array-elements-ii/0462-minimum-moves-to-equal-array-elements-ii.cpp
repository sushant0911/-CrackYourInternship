class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = (n%2) ? nums[n/2] : (nums[n/2]+nums[n/2 - 1])/2;
        int step = 0;
        for(int i = 0 ; i < n ; i++){
            step += abs(nums[i] - median);
        }
        return step;
        
        // int i = 0;
        // int j = n - 1;
        // sort(nums.begin(), nums.end());
        // int step = 0;
        // while(i < j){
        //     step += nums[j] - nums[i];
        //     i++;
        //     j--;
        // }
        // // if(i == j) step++;
        // return step;
    }
};