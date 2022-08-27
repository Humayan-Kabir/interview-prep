class Solution {
public:
    int maxProfit(vector<int>& prices) {
  		int profit = 0;
  		int minPrice = INT_MAX;
  		for(int p : prices) {
  			profit = max(profit, p - minPrice);
  			minPrice = min(minPrice, p);
  		}      
  		return profit;
    }
};