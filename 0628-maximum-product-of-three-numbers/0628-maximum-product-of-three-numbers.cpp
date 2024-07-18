class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Maximum product of three numbers can be either:
        // 1. The product of the three largest numbers
        // 2. The product of the two smallest numbers (which are negative) and the largest number
        int max1 = nums[n-1] * nums[n-2] * nums[n-3];
        int max2 = nums[0] * nums[1] * nums[n-1];
        
        return max(max1, max2);
    }
};