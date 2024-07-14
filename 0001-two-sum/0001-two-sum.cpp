class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int,int>> updatedArr;
        for(int i = 0 ; i < n ; i++){
            updatedArr.push_back({arr[i],i});
        }
        sort(updatedArr.begin(), updatedArr.end()); 
        int i = 0 ; 
        int j = n - 1;
        while(i < j){
            if(updatedArr[i].first + updatedArr[j].first == target) {
                return {updatedArr[i].second,updatedArr[j].second};
            }
            else if(updatedArr[i].first + updatedArr[j].first > target) j--;
            else if(updatedArr[i].first + updatedArr[j].first < target) i++;
        }
        return {0,0};
    }
};