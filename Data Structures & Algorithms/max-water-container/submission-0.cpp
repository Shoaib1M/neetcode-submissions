class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = INT_MIN;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int temp;
            for(int j = i+1;j<n;j++){
                temp = (j-i)*min(heights[i],heights[j]);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
