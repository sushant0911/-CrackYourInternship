class Solution {
public:
    int absolute(int n){
        return (n < 0)? (-1)*n : n;
    }
    
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int index;
        for(int i = 0 ; i < n ; i++){
            index = absolute(nums[i]) - 1;
            
            if(nums[index] < 0) ans.push_back(absolute(index + 1));
            else{
                nums[index] = nums[index] * (-1);
            }
        }
        return ans;
    }
};