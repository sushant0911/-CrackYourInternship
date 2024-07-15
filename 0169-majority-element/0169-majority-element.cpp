class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            if(element == nums[i]) c++;
        }
        return (c > n/2)? element : -1;
    }
};