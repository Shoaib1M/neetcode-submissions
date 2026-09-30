class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = INT_MAX;
        int n = prices.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            curmin = min(curmin,prices[i]);
            ans = max(ans,prices[i]-curmin);
        }
        return ans;
    }
};
