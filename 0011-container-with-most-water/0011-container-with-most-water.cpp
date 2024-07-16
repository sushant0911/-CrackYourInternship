class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int water;
        int n = height.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            water = min(height[left],height[right]) * (right - left);
            maxWater = max(maxWater,water);
            if(height[left] < height[right]) left++;
            else{
                right--;
            }
        }
        return maxWater;
    }
};