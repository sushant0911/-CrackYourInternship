class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int current = 0;
        int totalGas = 0;
        int totalCost = 0;
        for(int i = 0 ; i < n ; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalGas < totalCost) return -1;
        int start = 0;
        for(int i = 0 ; i < n ; i++){
            current += gas[i] - cost[i];
            if(current < 0){
                start = i + 1;
                current = 0;
            }
        }
        return start;
    }
};