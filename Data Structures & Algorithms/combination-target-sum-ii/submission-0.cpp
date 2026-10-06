class Solution {
    set<vector<int>> ans;
    void backtrack(vector<int> &candidates,int target,vector<int> &curr,int i,int total){
        if(total==target){
            ans.insert(curr);
            return;
        }
        if(total>target || i>=candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        backtrack(candidates,target,curr,i+1,total+candidates[i]);
        curr.pop_back();
        backtrack(candidates,target,curr,i+1,total);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        backtrack(candidates,target,curr,0,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
