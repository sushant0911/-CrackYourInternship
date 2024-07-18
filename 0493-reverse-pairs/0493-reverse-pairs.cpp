

class Solution {
public:
    int count = 0;
    
    void merge(vector<int> &nums, int left, int mid, int right){
        vector<int> temp;
        int i = left;
        int j = mid+1;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            } 
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= right){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k = left ; k <= right ; k++){
            nums[k] = temp[k - left];
        }
    }
    
    void countPairs(vector<int> &nums, int left, int mid , int right){
        int j = mid+1;
        for(int i = left; i <= mid ; i++){
            while(j <= right && nums[i] > 2LL * nums[j]){
                j++;
            }
            count += (j - (mid + 1));
        }
    }
    
    void mergeSort(vector<int> &nums, int left, int right){
        if(left >= right) return;
        int mid = (left + right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        countPairs(nums,left,mid,right);
        merge(nums,left,mid,right);
    }
    
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};