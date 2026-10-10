class Solution {

    int helper(vector<int> &nums){
        int rob1 = 0,rob2=0;
        for(int i = 0;i<nums.size();i++){
            int temp = max(nums[i]+rob1,rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
        int a = helper(nums1);
        int b = helper(nums2);
        int ans = max(a,b);
        return ans;
    }
};
