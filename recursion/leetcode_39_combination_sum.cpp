class Solution {
public:
    vector<vector<int>>ans;
    void fn(int ind,vector<int>&curr,int target,vector<int> &candidates){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0) return;
        if(ind==candidates.size()) return;
        
        curr.push_back(candidates[ind]);
        fn(ind,curr,target-candidates[ind],candidates);
        curr.pop_back();
        fn(ind+1,curr,target,candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n =candidates.size();
        vector<int> curr;
        fn(0,curr,target,candidates);
        return ans;
        
    }
};