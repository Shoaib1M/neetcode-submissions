class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0){
            return 0;
        }
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r){
            int temp = (r-l)*(min(heights[l],heights[r]));
            ans = max(ans,temp);
            if(heights[l]>=heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
