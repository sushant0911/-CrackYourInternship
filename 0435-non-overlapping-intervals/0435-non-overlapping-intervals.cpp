class Solution {
public:
    struct Remove{
        int start;
        int end;
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        Remove arr[n];
        for(int i = 0 ; i < n ; i++){
            arr[i].start = intervals[i][0];
            arr[i].end = intervals[i][1];
        }
        sort(arr, arr + n , [](Remove a, Remove b){ return a.end < b.end;});
        int count = 0;
        int j = 0;
        for(int i = 1 ; i < n ; i++){
            if(arr[i].start < arr[j].end){
                count++;
            }
            else{
                j = i;
            }
        }
        return count;
    }
};