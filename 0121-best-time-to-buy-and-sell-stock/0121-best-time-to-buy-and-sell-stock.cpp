class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProf = 0;
        int mini = prices[0];
        for(int i = 1 ; i < n ; i++){
            maxProf = max(maxProf,prices[i] - mini);
            mini = min(mini,prices[i]);
        }
        return maxProf;
    }
};