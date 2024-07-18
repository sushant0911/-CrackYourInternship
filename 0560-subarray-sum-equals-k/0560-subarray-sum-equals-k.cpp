class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        map<int,int> mpp;
        int prefixSum = 0; 
        int count = 0;
        mpp[0] = 1;
        while(i < n){
            prefixSum += nums[i];
            int rem = prefixSum - k;
            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }
            mpp[prefixSum]++;
            i++;
        }
        return count;
    }
};