/*
122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock.
You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
	Input: prices = [7,1,5,3,6,4]
	Output: 7
	Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
	Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
	Total profit is 4 + 3 = 7.

Example 2:
	Input: prices = [1,2,3,4,5]
	Output: 4
	Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
	Total profit is 4.
*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {

	int profit = 0;
	int prev = prices[0];
	for (int i = 1; i < prices.size(); i++) {

		// if price is higher than prev price, increase profit
		if (prev < prices[i]) {
			profit += prices[i] - prev;
		}

		// current price replaces prev price
		prev = prices[i];
	}

	return profit;
}

int main() {

	vector<int> prices = {1,2,3,4,5};
	cout << "maxProfit: " << maxProfit(prices) << endl;

	return 0;
}

