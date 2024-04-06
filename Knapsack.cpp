#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10;
    vector<int> weights = {2, 3, 4, 5, 4, 10, 12, 32, 13, 45, 32, 123, 43, 67, 45, 76, 42};
    vector<int> values = {3, 4, 11, 6, 11, 2, 32, 4, 23, 10, 32, 34, 21, 43, 46, 41, 8};

    cout << "Tong gia tri lon nhat co the: " << knapsack(W, weights, values) << endl;

    return 0;
}
