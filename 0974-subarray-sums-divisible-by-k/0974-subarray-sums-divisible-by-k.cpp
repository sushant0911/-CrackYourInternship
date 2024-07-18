class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int prefixSum = 0;
        map<int,int> mpp;
        mpp[0] = 1;
        for(int i = 0 ; i < n ; i++){
            prefixSum += nums[i];
            int remainder = prefixSum % k ;
            if(remainder < 0) remainder = remainder + k;
            if(mpp.find(remainder) != mpp.end()){
                count += mpp[remainder];
            }
            mpp[remainder]++;
        }
        return count;
    }
};