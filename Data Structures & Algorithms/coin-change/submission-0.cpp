class Solution {
public:
    int f(int ind, int T, vector<int>& coins) {
        if (ind == 0) {
            if (T % coins[0] == 0) return T / coins[0];
            return 1e9;
        }

        int notTake = f(ind - 1, T, coins);

        int take = INT_MAX;
        if (coins[ind] <= T) {
            take = 1 + f(ind, T - coins[ind], coins);
        }

        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);

        return ans >= 1e9 ? -1 : ans;
    }
};