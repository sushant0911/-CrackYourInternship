class StockSpanner {
public:
    StockSpanner() { }
    
    int next(int price) {
        int index = prices.size();
        prices.push_back(price);
        
        while (!indices.empty() && prices[indices.top()] <= price) {
            indices.pop();
        }
        
        int span = indices.empty() ? (index + 1) : (index - indices.top());
        indices.push(index);
        
        return span;
    }

private:
    vector<int> prices;       // Vector to store the stock prices
    stack<int> indices;       // Stack to store the indices of the stock prices
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */