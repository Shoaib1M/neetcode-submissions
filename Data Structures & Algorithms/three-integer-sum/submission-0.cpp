class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            int l = i+1;
            int r = n-1;
            vector<int> temp(3,0);
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum == 0){
                    temp[0]=(nums[i]);
                    temp[1]=(nums[l]);
                    temp[2]=(nums[r]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    l++;
                    r--;
                }
                else if(sum>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        vector<vector<int>> ans; 
        int len = st.size();
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
