class Solution {
 
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i,j = 0;
        for(int l = 0 ; l < n ; l++){
            if(nums[l] == 0){
                j = l;
                i = j + 1;
                break;
            }
        }
        while(i < n){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
    }
};